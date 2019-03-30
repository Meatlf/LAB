#include <jni.h>
#include <string>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
/**
 * power - Calculate the power of number.
 * @param base: Base value.
 * @param exponent: Exponent value.
 *
 * @return base raised to the power exponent.
 */
double power(double base, int exponent)
{
    int result = base;
    int i;

    if (exponent == 0) {
        return 1;
    }

    for(i = 1; i < exponent; ++i){
        result = result * base;
    }
    return result;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {

    double  base =3;
    int exponent =4;
    double result = power(base, exponent);
    printf("%g ^ %d is %g\n", base, exponent, result);

    std::string hello = "HelloWorld! Result = " + std::to_string(result);
    return env->NewStringUTF(hello.c_str());
}
