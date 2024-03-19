# -*- coding: utf-8 -*-
import os
import shutil
import json
import subprocess  # Import the subprocess module
import re  # Import the re module

def modify_project(config, project_dir):
     # 修改 build.gradle 文件中的包名 applicationId
    build_gradle_path = os.path.join(project_dir, 'app/build.gradle')
    
    with open(build_gradle_path, 'r') as f:
        build_gradle_content = f.read()

    
    # 使用更准确的正则表达式匹配并替换包名
    new_application_id = 'applicationId "{}"'.format(config["package_name"])
    pattern = r'applicationId\s+"[^"]+"'
    build_gradle_content = re.sub(pattern, new_application_id, build_gradle_content)
    

    with open(build_gradle_path, 'w') as f:
        f.write(build_gradle_content)

    # 修改 strings.xml 文件中的应用名 app_name
    string_xml_path = os.path.join(project_dir, 'app/src/main/res/values/strings.xml')

    with open(string_xml_path, 'r') as f:
        string_xml_content = f.read()
   
    
    # 使用更准确的正则表达式匹配并替换应用名
    new_app_name = '<string name="app_name">{}</string>'.format(config["app_name"])
    pattern = r'<string\s+name="app_name">[^<]+</string>'
    string_xml_content = re.sub(pattern, new_app_name, string_xml_content)
    
   
    with open(string_xml_path, 'w') as f:
        f.write(string_xml_content)

    # 修改指定的 Java 文件中的变量1和变量2
    java_file_path = os.path.join(project_dir, 'app/src/main/java/com/afdemo/game/AppsFlyerLibUtil.java')
    
    with open(java_file_path, 'r') as f:
        java_content = f.read()
   
    # 替换变量1 af_key
    new_af_key = 'af_key = "{}"'.format(config["af_key"])
    pattern_af_key = r'af_key\s*=\s*"[^"]+"'
    java_content = re.sub(pattern_af_key, new_af_key, java_content)

    # 替换变量2 url_kk
    new_url_kk = 'url_kk = "{}"'.format(config["url_kk"])
    pattern_url_kk = r'url_kk\s*=\s*"[^"]+"'
    java_content = re.sub(pattern_url_kk, new_url_kk, java_content)

    with open(java_file_path, 'w') as f:
        f.write(java_content)

def build_apk(project_dir):
    # Use Gradle to build the APK
    os.chdir(project_dir)
    result = subprocess.call(['gradlew.bat', 'assembleRelease'], stdout=subprocess.PIPE)
    if result != 0:
        print("Gradle build failed.")
        return False
    else:
        print("Gradle build succeeded.")
        return True

if __name__ == "__main__":
    # 获取用户输入的文件路径
    configurations_file = raw_input("Enter configurations file path: ")
    project_dir = raw_input("Enter project directory path: ")
    output_dir = raw_input("Enter output directory path: ")

    # 初始化计数器变量
    iterations = 0
    with open(configurations_file, 'r') as f:
        for line in f:
            config = json.loads(line.strip())  # Parse each line as a JSON object
            config_output_dir = os.path.join(output_dir, config["app_name"])  # Create a subdirectory for each config
            if not os.path.exists(config_output_dir):
                os.makedirs(config_output_dir)  # Ensure the subdirectory exists
            modify_project(config, project_dir)
            if build_apk(project_dir):
                # Construct the source path for the APK file
                apk_file_src = os.path.join(project_dir, 'app/build/outputs/apk/release/app-release.apk')
                # Construct the destination path for the APK file
                apk_file_dst = os.path.join(config_output_dir, '{}.apk'.format(config["app_name"]))
                # Copy the APK file to the output directory
                shutil.copy(apk_file_src, apk_file_dst)
            # 计数器递增
            iterations += 1
    # 循环结束后打印计数器的值
    print("apk num:", iterations)

