#include<stdio.h>
#include <arm_neon.h>

int main(){

	int8_t a_r[]={1,2,3,4,5,6,7,8};
	int8_t b_r[]={9,10,11,12,13,14,15};

	int8x8_t a = vld1_s8(a_r);
	int8x8_t b = vld1_s8(b_r);

	int8x8_t c = vadd_s8(a, b);

	return 0;
}