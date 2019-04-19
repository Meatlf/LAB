#include<stdio.h>
#include <arm_neon.h>

int main(){
		uint16x4_t a, b, c;
		uint16_t a_r[] = { 256,2,3,4 };
		uint16_t b_r[] = { 2 * 256,6,7,8 };
		a = vld1_u16(a_r);
		b = vld1_u16(b_r);
		c = vqdmulh_s16(a, b);
		b = vqdmulh_s16(a, c);
}
