#include <jni.h>
#include <string>
#include "include/hancnetsdk.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_wkq_jnidemo_JniUtil_stringFromJNI(JNIEnv *env, jclass clazz) {

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());

}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_wkq_jnidemo_JniUtil_HancNetInit(JNIEnv *env, jclass clazz) {
    return HancNetSDK_Init();
}


static jclass jClassString = NULL;

//jstring to char*
char *jstringTostring(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("utf-8");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1);
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    return rtn;
}

void NetCallback(int lUserID, char *pBuf, int nBufLen, long dwUser) {
    if (lUserID!=-1){

    }
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_wkq_jnidemo_JniUtil_netConnect(JNIEnv *env, jclass clazz, jstring ip, jint port,
                                        jstring link_cmd, jint timeout, jint cmdSize,
                                        jint dw_user) {
    char *jsIp = jstringTostring(env, ip);
    char *js_link_cmd = jstringTostring(env, link_cmd);
    int ss = HancNetSDK_Connect(jsIp, port, js_link_cmd, cmdSize, timeout, NetCallback, dw_user);
    return ss;
}