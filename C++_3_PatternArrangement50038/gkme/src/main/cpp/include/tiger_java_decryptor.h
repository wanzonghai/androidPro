//
// Created by ybpcn on 2023/10/8.
//

#ifndef HEADER_JAVA_DECRYPTOR_H
#define HEADER_JAVA_DECRYPTOR_H


#include <iostream>
#include <string>
#include "LoaderUtils.h"
#include <jni.h>

using namespace std;

class Decryptor
{
private:
    JNIEnv* env;

    jstring key;
    jobject secretKey;
    jobject cipher;

public:
    Decryptor(JNIEnv* env, const char* key);
    jbyteArray Decrypt(jbyteArray data);

private:
    void Init();
    void SetKey(jstring key);
};

#endif //HEADER_JAVA_DECRYPTOR_H
