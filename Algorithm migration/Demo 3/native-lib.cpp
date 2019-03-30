#include <jni.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "inc/MathFunctions.h"
#include "inc/fun.h"
#include "inc/add.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    double base = 4;
    int exponent = 5;
    double result = power(base, exponent);
    printf("%g ^ %d is %g\n", base, exponent, result);
    double result1 = function(base,exponent);
    printf("%g ^ %d is %g\n", base, exponent, result1);
    printf("add(3,4) = %d\n", add(3,4));

    std::string hello = "HelloWorld! Result = " + std::to_string(result);
    return env->NewStringUTF(hello.c_str());
}
