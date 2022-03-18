#include <jni.h>
#include "react-native-sql.h"


extern "C" JNIEXPORT void JNICALL
Java_com_reactnativesql_SqlModule_initialize(JNIEnv *env, jclass clazz, jlong jsiPtr, jstring docPath)
{
    jboolean isCopy;
    const char *docPathString = (env)->GetStringUTFChars(docPath, &isCopy); // This is might not be necessary, but my library moves files in the android file system, so this is just how to pass an android variable to the C++ size

    installSequel(*reinterpret_cast<jsi::Runtime *>(jsiPtr), docPathString);
}

extern "C" JNIEXPORT void JNICALL
Java_com_reactnativesql_SqlModule_destruct(JNIEnv *env, jclass clazz)
{
    cleanUpSequel();
}
