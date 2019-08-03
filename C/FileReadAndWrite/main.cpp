#include <stdio.h>
#include"define.h"

int main()
{
	uchar src_data[SRC_IMG_WIDTH  * (BITS >> 3) * CHANNELS * SRC_IMG_HEIGHT];
	uchar dst_data[DST_IMG_WIDTH  * (BITS >> 3) * CHANNELS * DST_IMG_HEIGHT];

	FILE *fp;

#if BITS==8
#if CHANNELS == 1
	errno_t err;
	if ((err = fopen_s(&fp, "..\\..\\data\\SrcImg_uchar_1_512_512.bin", "rb")) != 0) {
		printf("Can't open SrcImg_uchar_1_512_512.bin!\n");
		return 0;
	}
#elif CHANNELS == 3
	fp = fopen("..\\data\\input\\ratio2\\SrcImg_uchar_3_400_400.bin", "rb");
#endif

#elif BITS==16
#if CHANNELS == 1
	fp = fopen("..\\data\\input\\ratio2\\SrcImg_ushort_1_256_512.bin", "rb");
#elif CHANNELS == 3
	fp = fopen("..\\data\\input\\ratio2\\SrcImg_ushort_3_400_400.bin", "rb");
#endif

#elif BITS==32
#if CHANNELS == 1
	fp = fopen("..\\data\\input\\ratio2\\SrcImg_float_1_512_512.bin", "rb");
#elif CHANNELS == 3
	fp = fopen("..\\data\\input\\ratio2\\SrcImg_float_3_400_400.bin", "rb");
#endif
#endif

	fread(src_data, sizeof(
#if BITS == 8 
		uchar
#elif BITS == 16
		ushort
#elif BITS == 32
		float
#endif
		), SRC_IMG_WIDTH  * CHANNELS * SRC_IMG_HEIGHT, fp);
	fclose(fp);

#if BITS==8
#if CHANNELS == 1
	if ((err = fopen_s(&fp, "..\\..\\data\\DstImg_uchar_1_512_512.bin", "wb")) != 0) {
			printf("Can't open DstImg_uchar_1_512_512.bin!\n");
			return 0;
	}
#elif CHANNELS == 3
	fp = fopen("..\\data\\DstImg_uchar_3_400_400.bin", "wb");
#endif
#elif BITS==16
#ifdef TTZ_FOR_DEBUG == 1
	fp = fopen("..\\data\\DstImg_ushort_3_400_400.bin", "wb");
#elif TTZ_FOR_DEBUG == 2
	fp = fopen("..\\data\\dis_C_Tile_LoopUnrollong.bin", "wb");
#elif TTZ_FOR_DEBUG == 3
	fp = fopen("..\\data\\dis_CEVA.bin", "wb");
#endif
#elif BITS==32
#if CHANNELS == 1
	fp = fopen("..\\data\\DstImg_float_1_512_512.bin", "wb");
#elif CHANNELS == 3
	fp = fopen("..\\data\\DstImg_float_3_400_400.bin", "wb");
#endif
#endif
	fwrite(dst_data, sizeof(
#if BITS == 8
		uchar
#elif BITS == 16
		ushort
#elif BITS == 32
		float
#endif
		), DST_IMG_WIDTH * CHANNELS * DST_IMG_HEIGHT, fp);
	fclose(fp);
	return 0;
}
