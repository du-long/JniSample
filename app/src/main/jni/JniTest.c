
#include <jni.h>

jstring Java_top_itdl_jnisample_JniApi_getStringFormJni(JNIEnv *env, jclass type) {
    return (*env)->NewStringUTF(env, "I am Str from jni libs!");
}
