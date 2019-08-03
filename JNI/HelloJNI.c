// #include<jni.h>
// #include<stdio.h>
// #include"HelloJNI.h"

// // Implementation of native method sayHello() of HelloJNI class
// JNIEXPORT void JNICALL Java_HelloJNI_sayHello(JNIEnv * env,
// jobject thisObj)
// {
//     printf("Hello World!\n");
//     return;
// }

#include <jni.h>
#include <stdio.h>
#include "include\myjni_HelloJNI.h"

JNIEXPORT void JNICALL Java_myjni_HelloJNI_sayHello(JNIEnv *env, jobject thisObj) {
   printf("Hello World!\n");
   return;
}