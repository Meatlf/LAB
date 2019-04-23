/* A Simple C program to illustrate the use of Fixed Point Operations */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* DEFINE THE MACROS */
/* The basic operations perfomed on two numbers a and b of fixed
 point q format returning the answer in q format */
#define FADD(a,b) ((a)+(b))
#define FSUB(a,b) ((a)-(b))
#define FMUL(a,b,q) (((a)*(b))>>(q))
#define FDIV(a,b,q) (((a)<<(q))/(b))
 /* The basic operations where a is of fixed point q format and b is
  an integer */
#define FADDI(a,b,q) ((a)+((b)<<(q)))
#define FSUBI(a,b,q) ((a)-((b)<<(q)))
#define FMULI(a,b) ((a)*(b))
#define FDIVI(a,b) ((a)/(b))
  /* convert a from q1 format to q2 format */
#define FCONV(a, q1, q2) (((q2)>(q1)) ? (a)<<((q2)-(q1)) : (a)>>((q1)-(q2)))
/* the general operation between a in q1 format and b in q2 format
 returning the result in q3 format */
#define FADDG(a,b,q1,q2,q3) (FCONV(a,q1,q3)+FCONV(b,q2,q3))
#define FSUBG(a,b,q1,q2,q3) (FCONV(a,q1,q3)-FCONV(b,q2,q3))
#define FMULG(a,b,q1,q2,q3) FCONV((a)*(b), (q1)+(q2), q3)
#define FDIVG(a,b,q1,q2,q3) (FCONV(a, q1, (q2)+(q3))/(b))
 /* convert to and from floating point */

#define TOFIX(d, q) ((int)( (d)*(double)(1<<(q)) ))
#define TOFLT(a, q) ( (double)(a) / (double)(1<<(q)) )
#define TEST(FIX, FLT, STR) { \
 a = a1 = randint(); \
 b = bi = a2 = randint(); \
 fa = TOFLT(a, q); \
 fa1 = TOFLT(a1, q1); \
 fa2 = TOFLT(a2, q2); \
 fb = TOFLT(b, q); \
 ans1 = FIX; \
 ans2 = FLT; \
 printf("Testing %s\n fixed point answer=%f\n floating point answer=%f\n", \
 STR, TOFLT(ans1, q), ans2); \
}
int randint(void) {
	int i;
	i = rand();
	i = i & 32767;
	if (rand() & 1) i = -i;
	return i;
}
int main(void) {
	int q = 14, q1 = 15, q2 = 7, q3 = 14;
	double fa, fb, fa1, fa2;
	int a, b, bi, a1, a2;
	int ans1;
	double ans2;
	/* test each of the MACRO's with some random data */
	TEST(FADD(a, b), fa + fb, "FADD");
	TEST(FSUB(a, b), fa - fb, "FSUB");
	TEST(FMUL(a, b, q), fa*fb, "FMUL");
	TEST(FDIV(a, b, q), fa / fb, "FDIV");
	TEST(FADDI(a, bi, q), fa + bi, "FADDI");
	TEST(FSUBI(a, bi, q), fa - bi, "FSUBI");
	TEST(FMULI(a, bi), fa*bi, "FSUBI");
	TEST(FDIVI(a, bi), fa / bi, "FSUBI");
	TEST(FADDG(a1, a2, q1, q2, q3), fa1 + fa2, "FADDG");
	TEST(FSUBG(a1, a2, q1, q2, q3), fa1 - fa2, "FSUBG");
	TEST(FMULG(a1, a2, q1, q2, q3), fa1*fa2, "FMULG");
	TEST(FDIVG(a1, a2, q1, q2, q3), fa1 / fa2, "FDIVG");
	printf("Finished standard test\n");

	/* the following code will calculate exp(x) by summing the
series (not efficient but useful as an example) and compare it
with the actual value */
	while (1) {
		printf("Please enter the number to be exp'ed (<1): ");
		scanf_s("%lf", &fa, 128);
		printf(" x = %f\n", fa);
		printf(" exp(x) = %f\n", exp(fa));
		q = 14; /* set the fixed point */
		a = TOFIX(fa, q); /* get a in fixed point format */
		a1 = FCONV(1, 0, q); /* a to power 0 */
		a2 = 1; /* 0 factorial */
		ans1 = 0; /* series sum so far */
		for (bi = 0; bi < 10; bi++) { /* do ten terms of the series */
			int j;
			j = FDIVI(a1, a2); /* a^n/n! */
			ans1 = FADD(ans1, j);
			a1 = FMUL(a1, a, q); /* increase power of a by 1 */
			a2 = a2 * (bi + 1); /* next factorial */
			printf("Stage %d answer = %f\n", bi, TOFLT(ans1, q));
		}
	}
	return 0;
}