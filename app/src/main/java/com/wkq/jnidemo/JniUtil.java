package com.wkq.jnidemo;

/**
 * Jni 工具类
 */
public class JniUtil {
        static {
            System.loadLibrary("network");
            System.loadLibrary("HancNetSDK");
        }

    public static native String stringFromJNI();
    public static native boolean HancNetInit();
    public static native int netConnect(String ip,int port,String linkCmd,int timeout,int cmdSize,int dwUser);
}
