/*
参考资料： C Primer Plus 第6章 12.1.6 块作用域的静态变量
*/

#include<stdio.h>
void tryStatic(void);

int main(void)
{
    int count;

    for(count = 1; count <= 3; count++)
    {
        printf("Here comes iteration %d:\n", count);
        tryStatic();
    }
    return 0;
}

void tryStatic(void)
{
    int fade = 1;
    static int stay = 1;

    printf("fade = %d and stay = %d\n", fade++, stay++);
}
