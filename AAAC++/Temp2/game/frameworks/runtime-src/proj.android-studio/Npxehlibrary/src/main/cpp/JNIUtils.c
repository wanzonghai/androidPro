//
// Created by ybpcn on 2023/10/8.
//

#include <jni.h>
#include <android/log.h>
#include "JNIUtils.h"

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <malloc.h>
#include <errno.h>

void super(JNIEnv *env, jobject obj, const char *method, const char *sig, ...) {
    va_list args;
    va_start(args, sig);

    jclass selfClazz = (*env)->GetObjectClass(env, obj);
    jclass superClazz = (*env)->GetSuperclass(env, selfClazz);
    jmethodID mID = (*env)->GetMethodID(env, superClazz, method, sig);
    (*env)->CallNonvirtualVoidMethod(env, obj, superClazz, mID);
    va_end(args);
}

jobject getObjectField(JNIEnv *env, jclass clazz, const char *field, const char *sig,
                       jobject obj) {
    jfieldID fID = (*env)->GetFieldID(env, clazz, field, sig);
    return (*env)->GetObjectField(env, obj, fID);
}
jobject getObjectStaticField(JNIEnv *env, jclass clazz,
                             const char *field, const char * sig) {
    jfieldID fID = (*env)->GetStaticFieldID(env, clazz, field, sig);
    return  (*env)->GetStaticObjectField(env, clazz, fID);
}

void setObjectField(JNIEnv *env, jclass clazz, const char *field, const char *sig,
                    jobject obj, jobject value) {
    jfieldID fID = (*env)->GetFieldID(env, clazz, field, sig);
    (*env)->SetObjectField(env, obj, fID, value);
}

jobject callStaticObjectMethod(JNIEnv *env, jclass clazz,
                               const char *method, const char *sig, ...) {
    va_list args;
    va_start(args, sig);

    jmethodID mID = (*env)->GetStaticMethodID(env, clazz, method, sig);
    jobject obj = (*env)->CallStaticObjectMethodV(env, clazz, mID, args);
    va_end(args);
    return obj;
}

void callStaticVoidMethod(JNIEnv *env, jclass clazz,
                          const char *method, const char *sig, ...) {
    va_list args;
    va_start(args, sig);

    jmethodID mID = (*env)->GetStaticMethodID(env, clazz, method, sig);
    (*env)->CallStaticVoidMethodV(env, clazz, mID, args);
    va_end(args);
}


jobject callObjectMethod(JNIEnv *env, jclass clazz, jobject object,
                         const char *method, const char *sig, ...) {
    va_list args;
    va_start(args, sig);

    jmethodID mID = (*env)->GetMethodID(env, clazz, method, sig);
    jobject obj = (*env)->CallObjectMethodV(env, object, mID, args);
    va_end(args);
    return obj;
}

void callVoidMethod(JNIEnv *env, jclass clazz, jobject obj,
                    const char *method, const char *sig, ...) {
    va_list args;
    va_start(args, sig);

    jmethodID mID = (*env)->GetMethodID(env, clazz, method, sig);
    (*env)->CallVoidMethodV(env, obj, mID, args);
    va_end(args);
}

jboolean callBooleanMethod(JNIEnv *env, jclass clazz, jobject obj,
                           const char *method, const char *sig, ...) {
    va_list args;
    va_start(args, sig);

    jmethodID mID = (*env)->GetMethodID(env, clazz, method, sig);
    jboolean b = (*env)->CallBooleanMethodV(env, obj, mID, args);
    va_end(args);

    return b;
}

int jstringICmp(JNIEnv *env, jstring javaString1, jstring javaString2)
{
    const char *nativeString1 = (*env)->GetStringUTFChars(env, javaString1, 0);
    const char *nativeString2 = (*env)->GetStringUTFChars(env, javaString2, 0);

    /* Now you can compare nativeString1 with nativeString2*/
    int res = strcasecmp(nativeString1, nativeString2);

    /* And don't forget to release the handles */

    (*env)->ReleaseStringUTFChars(env, javaString1, nativeString1);
    (*env)->ReleaseStringUTFChars(env, javaString2, nativeString2);

    return res;
}



int mkdirs(const char *pathname, mode_t mode) {
    char *path = strdup(pathname), *p;
    errno = 0;
    for (p = path + 1; *p; ++p) {
        if (*p == '/') {
            *p = '\0';
            if (mkdir(path, mode) == -1) {
                if (errno != EEXIST)
                    return -1;
            }
            *p = '/';
        }
    }
    if (mkdir(path, mode) == -1) {
        if (errno != EEXIST)
            return -1;
    }
    free(path);
    return 0;
}

int ensure_dir(const char *path, mode_t mode) {
    if (access(path, R_OK) == -1)
        return mkdirs(path, mode);

    return 0;
}



static ssize_t read_eintr(int fd, void *out, size_t len) {
    ssize_t ret;
    do {
        ret = read(fd, out, len);
    } while (ret < 0 && errno == EINTR);
    return ret;
}

int read_full(int fd, void *out, size_t len) {
    while (len > 0) {
        ssize_t ret = read_eintr(fd, out, len);
        if (ret <= 0) {
            return -1;
        }
        out = (void *) ((uintptr_t) out + ret);
        len -= ret;
    }
    return 0;
}

int write_full(int fd, const void *buf, size_t count) {
    while (count > 0) {
        ssize_t size = write(fd, buf, count < SSIZE_MAX ? count : SSIZE_MAX);
        if (size == -1) {
            if (errno == EINTR)
                continue;
            else
                return -1;
        }

        buf = (const void *) ((uintptr_t) buf + size);
        count -= size;
    }
    return 0;
}
