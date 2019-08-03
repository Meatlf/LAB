#ifndef TEST_NEON2SSE
#define TEST_NEON2SSE

#ifdef WIN32
#include "NEON_2_SSE.h"
#else
#include <arm_neon.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif

void dilate_img_3x3(unsigned char* dst_data,
    unsigned char* src_data,
    int   img_width,
    int   img_height,
    int   threshold);

#ifdef __cplusplus
}
#endif
#endif