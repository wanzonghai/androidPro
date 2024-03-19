# -*- coding: utf-8 -*-
import argparse
import os
import shutil
import json
import subprocess  # Import the subprocess module

def modify_project(config, project_dir):
     # 修改 build.gradle 文件中的包名 applicationId
    build_gradle_path = os.path.join(project_dir, 'app/build.gradle')
    with open(build_gradle_path, 'r') as f:
        build_gradle_content = f.read()
    build_gradle_content = build_gradle_content.replace('applicationId ".*?"', 'applicationId "{}"'.format(config["package_name"]))
    with open(build_gradle_path, 'w') as f:
        f.write(build_gradle_content)

    # 修改 strings.xml 文件中的应用名 app_name
    string_xml_path = os.path.join(project_dir, 'app/src/main/res/values/strings.xml')
    with open(string_xml_path, 'r') as f:
        string_xml_content = f.read()
    string_xml_content = string_xml_content.replace('<string name="app_name">.*?</string>', '<string name="app_name">{}</string>'.format(config["app_name"]))
    with open(string_xml_path, 'w') as f:
        f.write(string_xml_content)

    # 修改指定的 Java 文件中的变量1和变量2
    java_file_path = os.path.join(project_dir, 'app/src/main/java/com/afdemo/game/AppsFlyerLibUtil.java')
    with open(java_file_path, 'r') as f:
        java_content = f.read()
    java_content = java_content.replace('af_key = ".*?"', 'af_key = "{}"'.format(config["af_key"]))
    java_content = java_content.replace('url_kk = ".*?"', 'url_kk = "{}"'.format(config["url_kk"]))
    with open(java_file_path, 'w') as f:
        f.write(java_content)

def build_apk(project_dir):
    # Use Gradle to build the APK
    os.chdir(project_dir)
    result = subprocess.call(['gradlew.bat', 'assembleDebug'], stdout=subprocess.PIPE)
    if result != 0:
        print("Gradle build failed.")
        return False
    else:
        print("Gradle build succeeded.")
        return True

if __name__ == "__main__":
    configurations_file = 'E:/AF/webPage/mjb_Afun_WebPage/android/configurations.txt'
    project_dir = 'E:/AF/webPage/mjb_Afun_WebPage/android'
    output_dir = 'E:/AF/webPage/mjb_Afun_WebPage/android/output'  # Update the output directory
    # 初始化计数器变量
    iterations = 0
    with open(configurations_file, 'r') as f:
        for line in f:
            config = json.loads(line.strip())  # Parse each line as a JSON object
            config_output_dir = os.path.join(output_dir, config["app_name"])  # Create a subdirectory for each config
            if not os.path.exists(config_output_dir):
                os.makedirs(config_output_dir)  # Ensure the subdirectory exists
            print("Config:", config)  # Print the config for debugging purposes
            print("Output directory:", config_output_dir)  # Print the output directory for debugging purposes
            modify_project(config, project_dir)
            if build_apk(project_dir):
                # Construct the source path for the APK file
                apk_file_src = os.path.join(project_dir, 'app/build/outputs/apk/debug/app-debug.apk')
                # Construct the destination path for the APK file
                apk_file_dst = os.path.join(config_output_dir, '{}.apk'.format(config["app_name"]))
                # Copy the APK file to the output directory
                shutil.copy(apk_file_src, apk_file_dst)
            # 计数器递增
            iterations += 1
    # 循环结束后打印计数器的值
    print("apk num:", iterations)

