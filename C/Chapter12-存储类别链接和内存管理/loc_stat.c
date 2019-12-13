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
