#include <opencv2/opencv.hpp>
#include"ImgProc.h"

int ImgProc::GaussianFilter()
{
	cv::Mat src = cv::imread("../data/input/lena.jpg", 1);
	cv::namedWindow("SrcImage", CV_WINDOW_AUTOSIZE);
	cv::imshow("SrcImage", src);
	cv::waitKey();

	cv::Mat dst;
	cv::Size ksize = cv::Size(5, 5);
	double sigmaX = 2;
	cv::GaussianBlur(src, dst, ksize, sigmaX);
	cv::imwrite("../data/output/Dstlena.jpg", dst);

	cv::namedWindow("DstImage", CV_WINDOW_AUTOSIZE);
	cv::imshow("DstImage", dst);
	cv::waitKey();
	return 0;
}

int ImgProc::Canny()
{
	cv::Mat src = cv::imread("../data/input/lena.jpg", 1);
	cv::namedWindow("SrcImage", CV_WINDOW_AUTOSIZE);
	cv::imshow("SrcImage", src);
	cv::waitKey();

	cv::Mat dst;

	double threshold1 = 2;
	double threshold2 = 5;

	cv::Canny(src, dst, threshold1, threshold2);

	cv::imwrite("../data/output/Dstlena.jpg", dst);

	cv::namedWindow("DstImage", CV_WINDOW_AUTOSIZE);
	cv::imshow("DstImage", dst);
	cv::waitKey();
	return 0;
}
