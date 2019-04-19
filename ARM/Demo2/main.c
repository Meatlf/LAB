#include <stdio.h>
int add(int i, int j)
{
int res = 0;
asm (
 "ADD %w[result], %w[input_i], %w[input_j]" //Use `%w[name]` to operate on W
// registers (as in this case).
// You can use `%x[name]` for X
// registers too, but this is the
// default.
: [result] "=r" (res)
: [input_i] "r" (i), [input_j] "r" (j)
);
return res;
}
int main(void)
{
int a = 1;
int b = 2;
int c = 0;
c = add(a,b);
printf("Result of %d + %d = %d\n", a, b, c);
}