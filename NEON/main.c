#include <stdio.h>
#include <stdlib.h>
#include<memory.h>
#include "dilate3x3.h"
#include"Neon_test.h"
#define  FILE_PATH "dilate_src.yuv"

int main()
{
	//vadd_s8_test();
	//vqadd_s8_test();
	//vqdmulh_s16_test();
	 //vceq_s8_test();
	//vtst_s8_test();



	dilate3x3_test();
	//vld1_u8_test();
	//vext_u8_test();
	//vcgt_u8_test();
	//threshold_test();
	//vshr_n_u8_test();
	return 0;
}