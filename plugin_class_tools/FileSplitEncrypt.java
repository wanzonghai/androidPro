//package com.toolsproject;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.List;
import java.util.Random;

import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.io.File;
import java.io.BufferedOutputStream;
import java.io.BufferedInputStream;

public class FileSplitEncrypt {
    static String[] TEMP_BYTE_U3D = new String[]{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
	static String[] TEMP_BYTE_CC = new String[]{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
	static String[] TEMP_FILE_TYPE_U3D = new String[]{".dat", ".data"};
	static String[] TEMP_FILE_TYPE_CC = new String[]{".png", ".jpg", ".json"};
	static int PROJECT_TYPE = 1;

    static String[] file_list = new String[]{};
    public static void main(String[] args) {
		PROJECT_TYPE = Integer.parseInt(args[2]);
		splitFileForYH(args[0], Integer.parseInt(args[1]));
//		rebackSomeFile();
    }
	
	private static void rebackSomeFile(String outFile){
		try{
			BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream(outFile));
			for(int i = 0; i < file_list.length; i++){
				BufferedInputStream bis = new BufferedInputStream(new FileInputStream(file_list[i]));
				byte[] bytes = new byte[1024];
				int len;
				while ((len = bis.read(bytes)) != -1) {
					for (int j = 0; j < len; j++) {
						bos.write(bytes[j] ^ 20230922);
					}
				}
				bis.close();
			}
			bos.close();
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	
	
	private static void splitFileForYH(String inFile, final int pwd){
		try{
			String fileWriteContent = "new String[]{";
			BufferedInputStream bis = new BufferedInputStream(new FileInputStream(inFile));
			byte[] bytes = new byte[1024];
			int len;
			String fileName = getFileName();
			String filePath = "E:\\TemplatePro\\plugin_class_tools\\splitFile\\" + fileName;
			fileWriteContent += "\"" + fileName + "\"" + ",";
			BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream(filePath));
			Random random = new Random();
			int writeLen = 0;
			int fileLen = 300 + random.nextInt(500);
			while ((len = bis.read(bytes)) != -1) {
				writeLen++;
                for (int i = 0; i < len; i++) {
                    //对写入的每个字节进行异或操作
                    bos.write(bytes[i] ^ pwd);
                }
				if(writeLen >= fileLen){
					bos.close();
					writeLen = 0;
					fileLen = 300 + random.nextInt(500);
					fileName = getFileName();
					filePath = "E:\\TemplatePro\\plugin_class_tools\\splitFile\\" + fileName;
					fileWriteContent += "\"" + fileName + "\"" + ",";
					bos = new BufferedOutputStream(new FileOutputStream(filePath));
				}
			}
			fileWriteContent = fileWriteContent.substring(0, fileWriteContent.length() - 1);
            fileWriteContent += "}";
            write_file(fileWriteContent, false);
			bos.close();
			bis.close();
		}catch (Exception e){
			e.printStackTrace();
		}
	}
	
	private static String getU3DFileName(){
        String fileName = "";
        Random random = new Random();
        int fileNamePath = 5 + random.nextInt(5);
        for (int NI = 0; NI < fileNamePath; NI++){
            int randIndex = random.nextInt(TEMP_BYTE_U3D.length);
            fileName += TEMP_BYTE_U3D[randIndex];
        }
        int fileTypeIndex = random.nextInt(TEMP_FILE_TYPE_U3D.length);
        fileName += TEMP_FILE_TYPE_U3D[fileTypeIndex];
        return fileName;
	}
	
	private static String getCCFileName(){
		String fileName = "";
        Random random = new Random();
		for(int i = 0; i < 8; i++){
			int randIndex = random.nextInt(TEMP_BYTE_CC.length);
			fileName += TEMP_BYTE_CC[randIndex];
		}
		fileName += "-";
		for(int i = 0; i < 4; i++){
			int randIndex = random.nextInt(TEMP_BYTE_CC.length);
			fileName += TEMP_BYTE_CC[randIndex];
		}
		fileName += "-";
		for(int i = 0; i < 4; i++){
			int randIndex = random.nextInt(TEMP_BYTE_CC.length);
			fileName += TEMP_BYTE_CC[randIndex];
		}
		fileName += "-";
		for(int i = 0; i < 4; i++){
			int randIndex = random.nextInt(TEMP_BYTE_CC.length);
			fileName += TEMP_BYTE_CC[randIndex];
		}
		fileName += "-";
		for(int i = 0; i < 12; i++){
			int randIndex = random.nextInt(TEMP_BYTE_CC.length);
			fileName += TEMP_BYTE_CC[randIndex];
		}
        int fileTypeIndex = random.nextInt(TEMP_FILE_TYPE_CC.length);
        fileName += TEMP_FILE_TYPE_CC[fileTypeIndex];
		return fileName;
	}

    private static String getFileName(){
        if(2 == PROJECT_TYPE){
			return getU3DFileName();
		}else{
			return getCCFileName();
		}
    }

    private static void write_file(String content, boolean isDelete){
        try{
            File file =new File("file_split_rote.txt");

            if(!file.exists()){
                file.createNewFile();
            }else{
                file.delete();
                file.createNewFile();
            }
            //使用true，即进行append file
            FileWriter fileWritter = new FileWriter(file.getName(),true);
            fileWritter.write(content);
            fileWritter.close();
            System.out.println("finish");
        }catch(IOException e){

            e.printStackTrace();

        }
    }
}


