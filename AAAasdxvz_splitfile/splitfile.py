# -*- coding: UTF-8 -*-
import os
import shutil
import sys

import codecs,re,linecache

pack_path_name = ''
pack_pass_word = ''
pack_rand_seed = ''

output_path = ''

#password 16
ENCRYPT_PWD = "sxbsifr7nja5mspo"

#seed
randomseed = ""

CUR_PATH = os.getcwd()


def doInput():
	global pack_path_name
	global pack_pass_word
	global pack_rand_seed
	
	# pack_path_name = raw_input(u'pack pathname:'.encode('gb18030')).encode('gb18030').decode(sys.stdin.encoding or locale.getpreferredencoding(True))
	pack_path_name = "E:\\bx_game\\mjb_plugins_developer_new\\EncryptJS_New\\release\\game-release.apk"
	pack_pass_word = raw_input(u'pack password:'.encode('gb18030')).encode('gb18030').decode(sys.stdin.encoding or locale.getpreferredencoding(True))
	pack_rand_seed = raw_input(u'pack randseed:'.encode('gb18030')).encode('gb18030').decode(sys.stdin.encoding or locale.getpreferredencoding(True))

def odFileJava(filename,outputpath,key,rand):
    cmd = ('javac splitfile.java')
    os.system(cmd)
    cmd = ('java splitfile' + ' ' + filename  + " " + outputpath  + " " +  key + " " + rand)
    os.system(cmd)
	

def create():
	global output_path

	output_path =  pack_path_name + '.new/'
	print("in path:%s"%(pack_path_name))
	print("out path:%s"%(output_path))

	ENCRYPT_PWD = pack_pass_word
	randomseed = pack_rand_seed

	odFileJava(pack_path_name,output_path,ENCRYPT_PWD,randomseed)


if __name__ == '__main__':
	doInput()
	#创建
	create() 
