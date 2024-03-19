//
// Created by ybpcn on 2023/10/9.
//

#ifndef GAMEAPP_GAMEENGINE_H
#define GAMEAPP_GAMEENGINE_H

#endif //GAMEAPP_GAMEENGINE_H

#include <string>

void Global_Init(JavaVM *);
void Global_Done(JavaVM *);

class CHxGameEngine {
    std::string m_Path;
    std::string m_PackageName;
    std::string m_TrackerName;
public:
    CHxGameEngine() {

    }
    bool InitGameEngine(JNIEnv* env, jobject thiz, jobject ctx);
    bool PluginCreate(JNIEnv *env, jobject thiz);
    bool LaunchActivity(JNIEnv *env, jobject thiz);

    void SetAdjustTrackerName(const char* szTrackerName);

    bool RaiseStartGameAEvent(JNIEnv* env, jobject  thiz);
    bool RaiseStartGameBEvent(JNIEnv* env, jobject  thiz);

private:
    bool  IsReady(JNIEnv *env, jobject ctx);

    bool SetReady(JNIEnv *env, jobject ctx);

    bool StartActivity(JNIEnv* env, jobject  ctx, jobject intent);
    bool RestartApp(JNIEnv* env);
};

extern CHxGameEngine* mg_pGameEngine;