#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnistudy_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++ AAA";
    return env->NewStringUTF(hello.c_str());
}

//extern "C" JNIEXPORT int JNICALL
//Java_com_example_jnistudy_MainActivity_Add(
//        JNIEnv *env,
//        jobject instance,
//        jint a,
//        jint b) {
//    jint sum = a + b;
//    return sum;
//}
