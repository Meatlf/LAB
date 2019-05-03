#include <stdio.h>
 #include <stdlib.h>

 void f(void)
 {
     void* s;
     s = malloc(5000); /* 申请内存空间 */
     return;  /* 内在泄漏 - 参见以下资料 */ 
     /* 
      * s 指向新分配的堆空间。
      * 当此函数返回，离开局部变量s的作用域后将无法得知s的值，
      * 分配的内存空间不能被释放。
      *
      * 如要「修复」这个问题，必须想办法释放分配的堆空间，
      * 也可以用alloca(3)代替malloc(3)。
      * （注意：alloca(3)既不是ANSI函数也不是POSIX函数）
      */
 }
 int main(void)
 {
     /* 该函数是一个死循环函数 */
     while (true) f(); /* Malloc函数迟早会由于内存泄漏而返回NULL*/
     return 0;
 }