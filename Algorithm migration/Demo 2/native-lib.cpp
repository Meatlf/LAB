#include <jni.h>
#include <string>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include "inc/MathFunctions.h"


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    double  base =3;
    int exponent =53;
    double result = power(base, exponent);
    printf("%g ^ %d is %g\n", base, exponent, result);

    std::string hello = "HelloWorld! Result = " + std::to_string(result);
    return env->NewStringUTF(hello.c_str());
}
