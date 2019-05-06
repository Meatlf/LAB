#include <opencv2/opencv.hpp>
#include "define.h"
#include"Core.h"

namespace Core {
	int HelloWorld() {
		cv::Mat img = cv::imread("../data/input/lena.jpg");
		if (img.empty())
		{
			std::cout << "´ò¿ªÍ¼ÏñÊ§°Ü£¡" << std::endl;
			return -1;
		}
		cv::namedWindow("image", CV_WINDOW_AUTOSIZE);
		cv::imshow("image", img);
		cv::waitKey();
	}

	int PictureCopy() {
		// read
		cv::Mat src = cv::imread("../data/input/lena.jpg", 1);

		if (!src.data)
		{
			printf("Can't open picture!\n");
			return -1;
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
		errno_t error = fopen_s(&fp,"../data/output/DstLena.bin", "wb");
		fwrite(dst_data, sizeof(char), WIDTH * 3 * HEIGHT, fp);
		cv::waitKey(0);
		src.release();
		cv::destroyWindow("RGB");
	}
}