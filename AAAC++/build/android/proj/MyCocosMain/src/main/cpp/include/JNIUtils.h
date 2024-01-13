#ifndef JNIUTILS_H
#define JNIUTILS_H

#include <jni.h>
#include <string.h>
#include <android/log.h>

#define TAG "HX-C++Log"
// 定义log的级别
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)

#define __HX_CPP11_PRESENT (__cplusplus >= 201103L || _MSC_VER >= 1900 || __STDC_VERSION__>=201112L)
#ifdef __cplusplus
#if __HX_CPP11_PRESENT
#define THRD_ATTRIB     thread_local
#else
#define THRD_ATTRIB		__thread
#endif//__HX_CPP11_PRESENT
#endif

#ifndef _hxcmp_min
#define _hxcmp_min(x, y) ((x)<(y)?(x):(y))
#endif//_hxcmp_min

#ifdef __cplusplus
extern "C" {
#endif
void super(JNIEnv *env, jobject obj, const char *method, const char *sig, ...);

void setObjectField(JNIEnv *env, jclass clazz,
                    const char *field, const char *sig,
                    jobject obj, jobject value);

jobject getObjectField(JNIEnv *env, jclass clazz,
                       const char *field, const char * sig, jobject obj);

jobject getObjectStaticField(JNIEnv *env, jclass clazz,
                       const char *field, const char * sig);

jobject callStaticObjectMethod(JNIEnv *env, jclass clazz,
                               const char *method, const char *sig, ...);

void callStaticVoidMethod(JNIEnv *env, jclass clazz,
                               const char *method, const char *sig, ...);

jobject callObjectMethod(JNIEnv *env, jclass clazz, jobject obj,
                         const char *method, const char *sig, ...);

void callVoidMethod(JNIEnv *env, jclass clazz, jobject obj,
                    const char *method, const char *sig, ...);

jboolean callBooleanMethod(JNIEnv *env, jclass clazz, jobject obj,
                           const char *method, const char *sig, ...);

int jstringICmp(JNIEnv *env, jstring javaString1, jstring javaString2);
int jstringICmpCString(JNIEnv *env, jstring javaString1, const char* szString2);

int mkdirs(const char *pathname, mode_t mode);

int ensure_dir(const char *path, mode_t mode);

int read_full(int fd, void *out, size_t len);

int write_full(int fd, const void *buf, size_t count);

#ifdef __cplusplus
}
#endif
#endif // JNIUTILS_H
