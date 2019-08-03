#ifdef WIN32
#define USE_ARM_NEON

#include "NEON_2_SSE.h"
#else
#include <arm_neon.h>
#include "Neon_test.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include<memory.h>
#include<malloc.h>
#include"Neon_test.h"
#include"dilate3x3.h"

#define FILE_PATH_SRC "../dilate_src.yuv"

#if !(defined USE_ARM_NEON)

#define  FILE_PATH_DST "../dilate_dst_no_arm_neon.yuv"

#endif

#if (defined USE_ARM_NEON)
#define  FILE_PATH_DST "../dilate_dst_arm_neon.yuv"
#endif

void vadd_s8_test()
{
	uint8x8_t a, b, c;
	uint8_t a_r[] = { 1, 2, 3, 4, 5, 6 , 7, 8 };
	uint8_t b_r[] = { 9, 10, 11, 12, 13, 14, 15, 16 };

	a = vld1_u8(a_r);
	b = vld1_u8(b_r);
	c = vadd_s8(a, b);
}

void vqadd_s8_test()
{
	int8x8_t a, b, c;
	int8_t a_r[] = { 1, 2, 3, 4, 5, 6 , 122, 112 };
	int8_t b_r[] = { 9, 10, 11, 12, 13, 122, 15, 16 };

	a = vld1_s8(a_r);
	b = vld1_s8(b_r);
	c = vqadd_s8(a, b);
}

void vqdmulh_s16_test()
{
	uint16x4_t a, b, c;
	uint16_t a_r[] = { 256,2,3,4 };
	uint16_t b_r[] = { 2 * 256,6,7,8 };
	a = vld1_u16(a_r);
	b = vld1_u16(b_r);
	c = vqdmulh_s16(a, b);
}

void vceq_s8_test()
{
	int8x8_t a[3], b[3];
	uint8x8_t c[3];

	uint8_t a_r[3][8] = {
	{ 1, 2, 3, 4, 5, 6, 7, 8 },
	{ 9, 10, 11, 12, 13, 14, 15 },
	{ 1, 2, 3, 4, 5, 6, 7, 8 }
	};

	uint8_t b_r[3][8] = {
	{ 1, 2, 3, 4, 5, 6, 7, 8 },
	{ 8, 10, 11, 12, 13, 14, 15 },
	{ 1, 2, 3, 4, 5, 6, 7, 8 }
	};

	a[0] = vld1_u8(a_r[0]);
	b[0] = vld1_u8(b_r[0]);
	c[0] = vceq_s8(a[0], b[0]);

	a[1] = vld1_u8(a_r[1]);
	b[1] = vld1_u8(b_r[1]);
	c[1] = vceq_s8(a[1], b[1]);

	a[2] = vld1_u8(a_r[2]);
	b[2] = vld1_u8(b_r[2]);
	c[2] = vceq_s8(a[2], a[2]);
}

void vtst_s8_test()
{
	uint8x8_t a[3], b[3];
	uint8x8_t c[3];

	uint8_t a_r[3][8] = {
	{ 1, 2, 3, 4, 5, 6, 7, 8 },
	{ 9, 10, 11, 12, 13, 14, 15 },
	{ 1, 2, 3, 4, 5, 6, 7, 8 }
	};

	uint8_t b_r[3][8] = {
	{ 1, 2, 3, 4, 5, 6, 7, 8 },
	{ 8, 10, 11, 12, 13, 14, 15 },
	{ 1, 2, 3, 4, 5, 6, 7, 8 }
	};

	a[0] = vld1_u8(a_r[0]);
	b[0] = vld1_u8(b_r[0]);
	c[0] = vtst_u8(a[0], b[0]);

	a[1] = vld1_u8(a_r[1]);
	b[1] = vld1_u8(b_r[1]);
	c[1] = vtst_u8(a[1], b[1]);

	a[2] = vld1_u8(a_r[2]);
	b[2] = vld1_u8(b_r[2]);
	c[2] = vtst_u8(a[2], b[2]);
}

void dilate3x3_test()
{
	int i;
	int framnum = 100;
	int width = 1600;
	int height = 800;
	int thresh = 60;
	int threshdilate = 2;


	unsigned char *src = NULL;
	unsigned char *dst = NULL;

	FILE *fp_i = NULL;
	FILE *fp_o = NULL;

	src = _aligned_malloc(width * height * 3, 128);

	if (src == NULL)
	{
		return -1;
	}

	dst = src + width * height * 3 / 2;

	memset(src, 0x0, width * height * 5 / 2);
	memset(dst + width * height, 0x80, width * height / 2);

	fopen_s(&fp_i, FILE_PATH_SRC, "rb");
	if (fp_i == NULL)
	{
		return -1;
	}

	fopen_s(&fp_o, FILE_PATH_DST, "wb");
	if (fp_o == NULL)
	{
		return -1;
	}

	for (i = 0; i < framnum; i++)
	{
		fread(src, width * height * 3 / 2, 1, fp_i);

		//for (j = 0; j < width * height; j ++)
		//{
		//    *(src + j) = (*(src + j) > thresh);
		//}

		//memcpy(dst, src, width * height);
		dilate_img_3x3(dst, src, width, height, threshdilate);

		fwrite(dst, width * height * 3 / 2, 1, fp_o);
	}

	fclose(fp_i);
	fclose(fp_o);

	_aligned_free(src);
}

void vld1_u8_test() {
	uint8x8_t a, b, c;
	uint8_t* A;
	uint8_t a_r[] = { 1, 2, 3, 4, 5, 6 };
	uint8_t b_r[] = { 9, 10, 11, 12, 13, 14, 15, 16 };

	a = vld1_u8(a_r);
	b = vld1_u8(b_r);
	c = vadd_s8(a, b);
	//c = vcgt_u8(b, a);
}

void vext_u8_test() {
	uint8x16_t a;
	uint8x8_t b, c;
	uint8_t a_r[] = { 1, 2, 3, 4, 5, 6, 7, 8,  9, 10, 11, 12, 13, 14, 15, 16 };

	a = vld1q_u8(a_r);
	// ָ��ָ��a������������һλ����ȡ8��Ԫ��
	b = vext_u8(vget_low_u8(a), vget_high_u8(a), 1);
	// ָ��ָ��a������������һλ����ȡ8��Ԫ��
	c = vext_u8(vget_low_u8(a), vget_high_u8(a), 2);
}

void vcgt_u8_test()
{
	uint8x8_t a1, b1, c1, a2, b2, c2, a3, b3, c3;
	uint8_t a1_r[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	uint8_t b1_r[] = { 0, 10, 11, 12, 13, 14, 15 };

	a1 = vld1_u8(a1_r);
	b1 = vld1_u8(b1_r);
	c1 = vcgt_u8(b1, a1);

	uint8_t a2_r[] = { 9, 10, 11, 12, 13, 14, 15 };
	uint8_t b2_r[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	a2 = vld1_u8(a2_r);
	b2 = vld1_u8(b2_r);
	c2 = vcgt_u8(b2, a2);

	uint8_t a3_r[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	uint8_t b3_r[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	a3 = vld1_u8(a3_r);
	b3 = vld1_u8(b3_r);
	c3 = vcgt_u8(b3, a3);
}

void threshold_test()
{
	unsigned char a;
	int sum, threshold;

	sum = 2;
	threshold = 5;
	a = (unsigned char)(sum > threshold);


	sum = 5;
	threshold = 2;
	a = (unsigned char)(sum > threshold);

	sum = 5;
	threshold = 5;
	a = (unsigned char)(sum > threshold);

}

void vshr_n_u8_test()
{
	uint8x8_t a, c;
	const int b = 7;
	uint8_t a_r[] = { 124, -1, -1, -1, 4, 5, 6, 7 };

	a = vld1_u8(a_r);
	c = vshr_n_u8(a, b);
}
