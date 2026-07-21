#include <jni.h>
#include <stdlib.h>
#include <string.h>

JNIEXPORT jint JNICALL Java_arc_util_NativeUtils_setEnv(
    JNIEnv *env, jclass cls, jstring name, jstring value, jboolean overwrite)
{
    const char *n = (*env)->GetStringUTFChars(env, name, 0);
    const char *v = (*env)->GetStringUTFChars(env, value, 0);
    int result = setenv(n, v, overwrite ? 1 : 0);
    (*env)->ReleaseStringUTFChars(env, name, n);
    (*env)->ReleaseStringUTFChars(env, value, v);
    return (jint)result;
}

JNIEXPORT jint JNICALL Java_arc_util_NativeUtils_unsetEnv(
    JNIEnv *env, jclass cls, jstring name)
{
    const char *n = (*env)->GetStringUTFChars(env, name, 0);
    int result = unsetenv(n);
    (*env)->ReleaseStringUTFChars(env, name, n);
    return (jint)result;
}

JNIEXPORT jstring JNICALL Java_arc_util_NativeUtils_getEnv(
    JNIEnv *env, jclass cls, jstring name)
{
    const char *n = (*env)->GetStringUTFChars(env, name, 0);
    const char *v = getenv(n);
    (*env)->ReleaseStringUTFChars(env, name, n);
    return v ? (*env)->NewStringUTF(env, v) : NULL;
}
