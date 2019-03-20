#ifndef NEON_TEST_H
#define NEON_TEST_H

// 加法
void vadd_s8_test();
void vqadd_s8_test();

// 乘法
void vqdmulh_s16_test();

// 比较
void vceq_s8_test();
void vtst_s8_test();

void dilate3x3_test();
void vld1_u8_test();
void vext_u8_test();
void vcgt_u8_test();
void threshold_test();
void vshr_n_u8_test();
#endif // !NEON_TEST_H
