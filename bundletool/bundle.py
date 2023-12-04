# -*- coding: UTF-8 -*-
import os
import shutil
import sys

aab_path = ''
bundlejar_path = 'bundletool-all-1.9.1.jar'
keystore_path = ''
keystore_pwd = ''
keystore_alias = ''
keystore_key_pwd = ''

CUR_PATH = os.getcwd()


def doInput():
	#global bundlejar_path
	global aab_path
	global keystore_path
	global keystore_alias
	global keystore_pwd
	global keystore_key_pwd
	
	#bundlejar_path = raw_input(u'输入bundlejar地址:'.encode('gb18030')).decode(sys.stdin.encoding or locale.getpreferredencoding(True))
	aab_path = raw_input("aab path:")
	keystore_path = raw_input("keystore path:")
	keystore_alias = raw_input("alias name:")
	keystore_pwd = raw_input("keystore pwd:")
	keystore_key_pwd = raw_input("alias pwd:")

def installApks():
	#安装apks到手机
	print ('installApks start')
	filename = aab_path.split('\\')[-1].split('.')[0]
	cmd = bundlejar_path + ' install-apks --apks=' + CUR_PATH + '\\' + filename +'.apks'
	print (cmd)
	os.system(cmd)

def aab_to_apks():
	#将aab文件转换成apks文件
	filename = aab_path.split('\\')[-1].split('.')[0]
	cmd = (bundlejar_path + ' build-apks --bundle=' + aab_path + ' --output=' + CUR_PATH + '\\' + filename +'.apks' + ' --ks=' + keystore_path + ' --ks-pass=pass:' + keystore_pwd + ' --ks-key-alias=' + keystore_alias + ' --key-pass=pass:' + keystore_key_pwd)
	os.system(cmd)

def DeleteFile(strFileName):
        fileName = str(strFileName)
        if os.path.isfile(fileName):
                try:
                        os.remove(fileName)
                except:
                        pass
            
if __name__ == '__main__':
        DeleteFile('CashRummy.apks')
        doInput()
        aab_to_apks()
        installApks()
