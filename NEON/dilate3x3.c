#include "dilate3x3.h"
#define USE_ARM_NEON

#if !(defined USE_ARM_NEON)
void dilate_img_3x3(unsigned char* dst_data,
						  unsigned char* src_data, 								    	      
						  int   img_width, 
						  int   img_height, 
						  int   threshold)
{
	int           i, j, m;
	int           sum;
	unsigned char *dst, *src;
	unsigned char *start_pos;

	/*��ʼ��ǰ������*/
	memset(dst_data, 0, img_width * img_height);

	//������ʼ��λ��
	src  = src_data  + img_width;
	dst  = dst_data  + img_width;

	//��ÿ�����ص�����˲�����
	for (i = 1; i < img_height - 1; i ++)
	{
		for (j = 1; j < img_width - 1; j ++)
		{
			sum = 0;
			start_pos = src - img_width + j - 1;

			//ÿ�����ص�3x3��Χ��ǰ�����ۼ�
			for (m = 0; m < 3; m++)
			{
				sum += start_pos[0] + start_pos[1] + start_pos[2];
				start_pos += img_width;
			}

			//���趨��ֵ���бȽ�
            //dst[j] = (unsigned char)(sum > threshold) * 255;
			dst[j] = (unsigned char)(sum > threshold);
		}
		src  += img_width;
		dst  += img_width;
	}
}
#endif // _DEBUG

#if (defined USE_ARM_NEON)
/***********************************************************************************************************************
* ��  �ܣ�ͼ��3x3���ʹ���(������ʴ)�����������Ŀ��ͼ���� (neon �汾)
* ��  ����IN:
*         src_data-------------------------------------ͼ�����ݻ���
*         img_width------------------------------------ͼ�����
*         img_height-----------------------------------ͼ��߶�
*         threshold------------------------------------��ֵ
*		 OUT:
*		  dst_data-------------------------------------������ݻ���
* ����ֵ�����ش�����
***********************************************************************************************************************/
void   dilate_img_3x3(unsigned char*     dst_data,
					  unsigned char*     src_data,
					  int      img_width,
					  int      img_height,
					  int      threshold)
{
	int i, j, width_tmp;
	uint8x16_t line0, line1, line2;
	uint8x8_t  vext1, vext2, vthreshold;

	width_tmp   = (img_width - 2) >> 3;
	img_height  -= 2;
	dst_data   += img_width + 1;
	src_data   += img_width;

	vthreshold  = vmov_n_u8((uint8_t) threshold);
	for(i = img_height; i > 0; i--)
	{
		for(j = width_tmp; j > 0; j--)
		{
			//������������,ÿ��16��Ԫ��
			line0 = vld1q_u8((uint8_t*)src_data - img_width);
			line1 = vld1q_u8((uint8_t*)src_data); 
			line2 = vld1q_u8((uint8_t*)src_data + img_width); 

			//line0 ���ǰ����֮��
			line0 = vaddq_u8(line0, line1);
			line0 = vaddq_u8(line0, line2);

			vext1 = vext_u8(vget_low_u8(line0), vget_high_u8(line0), 1);
			vext2 = vext_u8(vget_low_u8(line0), vget_high_u8(line0), 2);

			vext1 = vadd_u8(vext1, vget_low_u8(line0));
			vext1 = vadd_u8(vext1, vext2);

			//line0����ֵ�Ƚϣ����ڷ���ȫ1����������7λ��С�ڷ���ȫ0
			vext1 = vcgt_u8(vext1, vthreshold);
			vext1 = vshr_n_u8(vext1, 7);

			vst1_u8((uint8_t*) dst_data, vext1);
			src_data += 8;
			dst_data += 8;
		}

		//���������6��
		{
			//������������
			line0 = vld1q_u8((uint8_t*)src_data - img_width);
			line1 = vld1q_u8((uint8_t*)src_data); 
			line2 = vld1q_u8((uint8_t*)src_data + img_width); 

			//line0 ���ǰ����֮��
			line0 = vaddq_u8(line0, line1);
			line0 = vaddq_u8(line0, line2);

			vext1 = vext_u8(vget_low_u8(line0), vget_high_u8(line0), 1);
			vext2 = vext_u8(vget_low_u8(line0), vget_high_u8(line0), 2);

			vext1 = vadd_u8(vext1, vget_low_u8(line0));
			vext1 = vadd_u8(vext1, vext2);

			//line0����ֵ�Ƚϣ����ڷ���ȫ1����������7λ��С�ڷ���ȫ0
			vext1 = vcgt_u8(vext1, vthreshold);
			vext1 = vshr_n_u8(vext1, 7);

			vst1_lane_u32((uint32_t *)dst_data, vreinterpret_u32_u8(vext1), 0);
			vst1_lane_u16((uint16_t *)dst_data + 2, vreinterpret_u16_u8(vext1), 2);

			src_data += 8;
			dst_data += 8;
		}
	}
}

#endif
