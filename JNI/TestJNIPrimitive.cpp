#include<jni.h>
#include<iostream>
#include"TestJNIPrimitive.h"

JNIEXPORT jdouble JNICALL Java_TestJNIPrimitive_average
  (JNIEnv *, jobject, jint, jint)
  {
      jdouble result;
      printf("In C, the number are %d and %d\n", n1, n2);
      result = ((jdouble)n1 + n2) / 2.0;
      return result;
  }