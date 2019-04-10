#include <opencv2/opencv.hpp>
#include "define.h"
#include"Core.h"

namespace Core {
	void PictureCopy() {
		// read
		cv::Mat src = cv::imread("lena.jpg", 1);

		if (!src.data)
		{
			printf("Can't open picture!\n");
		}
		FILE *fp;

		cv::namedWindow("RGB", cv::WINDOW_AUTOSIZE);
		cv::imshow("RGB", src);

		// function
		const int channels = src.channels();

		cv::MatIterator_<cv::Vec3b> it, end;
		unsigned char dst_data[WIDTH * 3 * HEIGHT];
		int nRows = src.rows;
		int nCols = src.cols*channels;

		int i, j;
		uchar* p;
		for (i = 0; i < nRows; ++i)
		{
			p = src.ptr<uchar>(i);
			for (j = 0; j < nCols; j += 3)
			{
				dst_data[i * nCols + j] = p[j];
				dst_data[i * nCols + j + 1] = p[j + 1];
				dst_data[i * nCols + j + 2] = p[j + 2];
			}
		}

		// write
		fp = fopen("./data/output/DstLena.bin", "wb");
		fwrite(dst_data, sizeof(char), WIDTH * 3 * HEIGHT, fp);
		cv::waitKey(0);
		src.release();
		cv::destroyWindow("RGB");
	}
}