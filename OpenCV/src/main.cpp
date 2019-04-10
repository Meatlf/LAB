//// Pyramid L-K optical flow example
////
//#include <opencv2/opencv.hpp>
//#include <iostream>
//using namespace std;
//static const int MAX_CORNERS = 1000;
//void help(int** argv) {
//	cout << "Call: " << argv[0] << " [image1] [image2]" << endl;
//	cout << "Demonstrates Pyramid Lucas-Kanade optical flow." << endl;
//}
//int main(int argc, char** argv) {
//	//if (argc != 3) { help(&argv); exit(-1); }
//	// Initialize, load two images from the file system, and
//	// allocate the images and other structures we will need for
//	// results.
//	//
//	cv::Mat imgA = cv::imread("1525419888677686000.png", cv::IMREAD_GRAYSCALE);
//	cv::Mat imgB = cv::imread("1525419888710986000.png", cv::IMREAD_GRAYSCALE);
//	cv::Size img_sz = imgA.size();
//	int win_size = 10;
//	cv::Mat imgC = cv::imread("1525419888710986000.png", cv::IMREAD_GRAYSCALE);
//	// The first thing we need to do is get the features
//	// we want to track.
//	//
//	vector< cv::Point2f > cornersA, cornersB;
//	const int MAX_CORNERS = 500;
//	cv::goodFeaturesToTrack(
//		imgA, // Image to track
//		cornersA, // Vector of detected corners (output)
//		MAX_CORNERS, // Keep up to this many corners
//		0.01, // Quality level (percent of maximum)
//		5, // Min distance between corners
//		cv::noArray(), // Mask
//		3, // Block size
//		false, // true: Harris, false: Shi-Tomasi
//		0.04 // method specific parameter
//	);
//	cv::cornerSubPix(
//		imgA, // Input image
//		cornersA, // Vector of corners (input and output)
//		cv::Size(win_size, win_size), // Half side length of search window
//		cv::Size(-1, -1), // Half side length of dead zone (-1=none)
//		cv::TermCriteria(
//			cv::TermCriteria::MAX_ITER | cv::TermCriteria::EPS,
//			20, // Maximum number of iterations
//			0.03 // Minimum change per iteration
//		)
//	);
//	// Call the Lucas Kanade algorithm
//	//
//	vector<uchar> features_found;
//	cv::calcOpticalFlowPyrLK(
//		imgA, // Previous image
//		imgB, // Next image
//		cornersA, // Previous set of corners (from imgA)
//		cornersB, // Next set of corners (from imgB)
//		features_found, // Output vector, elements are 1 for tracked
//		cv::noArray(), // Output vector, lists errors (optional)
//		cv::Size(win_size * 2 + 1, win_size * 2 + 1), // Search window size
//		5, // Maximum pyramid level to construct
//		cv::TermCriteria(
//			cv::TermCriteria::MAX_ITER | cv::TermCriteria::EPS,
//			20, // Maximum number of iterations
//			0.3 // Minimum change per iteration
//		)
//	);
//	// Now make some image of what we are looking at:
//	// Note that if you want to track cornersB further, i.e.
//	// pass them as input to the next calcOpticalFlowPyrLK,
//	// you would need to "compress" the vector, i.e., exclude points for which
//	// features_found[i] == false.
//	for (int i = 0; i < (int)cornersA.size(); i++) {
//		if (!features_found[i])
//			continue;
//	}
//	cv::imshow("ImageA", imgA);
//	cv::imshow("ImageB", imgB);
//	cv::imshow("LK Optical Flow Example", imgC);
//	cv::waitKey(0);
//	return 0;
//}

//// Pyramid L-K optical flow example
//#include<opencv2/opencv.hpp>
//#include<iostream>
//#include<vector>
//#define DEBUG
//void help(char** argv) {
//	std::cout << "Call: " << argv[0] << "[image1] [image2]" << std::endl;
//	std::cout << "Demonstrates Pyramid LK flow." << std::endl;
//}
//int main(int argc, char** argv) {
//	if (argc != 3) {
//		help(argv);
//		exit(-1);
//	}
//
//	// 加载前后帧两幅图片
//	//
//	cv::Mat imgA = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
//	cv::Mat imgB = cv::imread(argv[2], cv::IMREAD_GRAYSCALE);
//	cv::Size img_sz = imgA.size();
//	int win_size = 10;
//	cv::Mat imgC = cv::imread(argv[2], cv::IMREAD_GRAYSCALE);
//
//	// 找出特征点
//	std::vector< cv::Point2f > cornersA, cornersB;
//	const int MAX_CORNERS = 500;
//	cv::goodFeaturesToTrack(
//		imgA,			// 输入：待提取特征点的图像
//		cornersA,		// 输出：检测出来的特征点构成的Vector
//		MAX_CORNERS,	// 确定提取特征点的数量
//		0.01,			// Quality level (percent of maximum)
//		5,				// 特征点间最小的距离
//		cv::noArray(),	// Mask
//		3,				// 块大小
//		false,				// 选择提取特征点的算法 true：Harris，false：Shi-Tomasi
//		0.04
//	);
//
//#ifdef DEBUG
//	std::cout <<"左帧图特征点的个数为："<< cornersA.size() << std::endl;
//	std::cout << "第一个特征点的坐标为：x: " << cornersA[0].x << " y: "<<cornersA[0].y << std::endl;
//#endif // DEBUG
//
//	cv::cornerSubPix(
//		imgA, // Input image
//		cornersA, // Vector of corners (input and output)
//		cv::Size(win_size, win_size), // Half side length of search window
//		cv::Size(-1, -1), // Half side length of dead zone (-1=none)
//		cv::TermCriteria(
//			cv::TermCriteria::MAX_ITER | cv::TermCriteria::EPS,
//			20, // Maximum number of iterations
//			0.03 // Minimum change per iteration
//		)
//	);
//
//	std::vector<uchar> feature_found;
//	cv::calcOpticalFlowPyrLK(
//		imgA,	// 输入：左帧图
//		imgB,	// 输入：右帧图
//		cornersA,	// 输入：左帧图中特征点组成的Vector
//		cornersB,	// 输出：右帧图中特征点组成的Vector
//		feature_found,		// Vector类型，对于左帧图中的每个点，在右帧图中能够成功追踪则返回1，没有则返回0
//		cv::noArray(),	// 发现点的误差测量
//		cv::Size(win_size*2+1,win_size*2+1),		// 窗口大小
//		5,		// 金字塔的层数
//		cv::TermCriteria(
//			cv::TermCriteria::MAX_ITER | cv::TermCriteria::EPS,
//			20, // Maximum number of iterations
//			0.3) // Minimum change per iteration
//			// 结束寻找的方式，一般默认就好
//		);
//
//#ifdef DEBUG
//	std::cout << "右帧图特征点的个数为：" << cornersB.size() << std::endl;
//	std::cout << "第一个特征点的坐标为：x: " << cornersB[0].x << " y: " << cornersB[0].y << std::endl;
//#endif // DEBUG
//
//	// 显示原图像
//	cv::imshow("imgA", imgA);
//	cv::imshow("imgB", imgB);
//	// 画出特征点
//	cv::Mat img_show_A = imgA.clone();
//	for (auto corA : cornersA)
//		cv::circle(img_show_A, corA, 10, cv::Scalar(0, 240, 0), 1);
//	cv::imshow("cornersA", img_show_A);
//
//	cv::Mat img_show_B = imgB.clone();
//	for (auto corB : cornersB)
//		cv::circle(img_show_B, corB, 10, cv::Scalar(0, 240, 0), 1);
//	cv::imshow("cornersB", img_show_B);
//	cv::waitKey(0);
//	// LK光流计算
//	std::cout << "Done!" << std::endl;
//}
//


//#include <opencv2/opencv.hpp>
//
//void matrixInverse3x3(const float src[9], float dst[9])
//{
//	float f1 = src[4] * src[8] - src[5] * src[7];
//	float f2 = src[5] * src[6] - src[3] * src[8];
//	float f3 = src[3] * src[7] - src[4] * src[6];
//
//	float det = src[0] * f1 + src[1] * f2 + src[2] * f3;
//	det = (det != 0) ? float(1) / det : 0;
//
//	dst[0] = f1 * det;
//	dst[1] = (src[7] * src[2] - src[1] * src[8]) * det;
//	dst[2] = (src[1] * src[5] - src[4] * src[2]) * det;
//	dst[3] = f2 * det;
//	dst[4] = (src[0] * src[8] - src[6] * src[2]) * det;
//	dst[5] = (src[2] * src[3] - src[0] * src[5]) * det;
//	dst[6] = f3 * det;
//	dst[7] = (src[6] * src[1] - src[0] * src[7]) * det;
//	dst[8] = (src[0] * src[4] - src[3] * src[1]) * det;
//}
//
//template<typename T>
//static void bilinear_(const T* sptr, int srcStep, int w, int h, int cn, double x, double y, T* dptr)
//{
//	srcStep /= sizeof(*sptr);
//
//	// out of range
//	if (x < 0 || x >(double)(w - 1) || y < 0 || y >(double)(h - 1))
//	{
//		memset(dptr, 0, sizeof(T)* cn);
//		return;
//	}
//
//	// otherwise
//	int left = (int)floor(x);
//	int right = MIN(left + 1, w - 1);
//	int top = (int)floor(y);
//	int bottom = MIN(top + 1, h - 1);
//
//	double dx0 = x - left;
//	double dy0 = y - top;
//
//	const T* v00 = sptr + top * srcStep + left * cn;
//	const T* v01 = sptr + top * srcStep + right * cn;
//	const T* v10 = sptr + bottom * srcStep + left * cn;
//	const T* v11 = sptr + bottom * srcStep + right * cn;
//	for (int i = 0; i < cn; ++i)
//	{
//		double mt = v00[i] + (v01[i] - v00[i]) * dx0;
//		double mb = v10[i] + (v11[i] - v10[i]) * dx0;
//		dptr[i] = (T)(mt + (mb - mt) * dy0);
//	}
//}
//
//template<typename T>
//static void affineTransform_(const T* sptr, int srcStep, int srcWidth, int srcHeight,
//	T* dptr, int dstStep, int dstWidth, int dstHeight, int cn, const float* xformCoeff)
//{
//	dstStep /= sizeof(*dptr);
//#pragma omp parallel for
//	for (int dy = 0; dy < dstHeight; ++dy)
//	{
//		T* dptrCurr = dptr + dy * dstStep;
//		for (int dx = 0; dx < dstWidth; ++dx)
//		{
//			double sx = xformCoeff[0] * dx + xformCoeff[1] * dy + xformCoeff[2];
//			double sy = xformCoeff[3] * dx + xformCoeff[4] * dy + xformCoeff[5];
//			bilinear_(sptr, srcStep, srcWidth, srcHeight, cn, sx, sy, dptrCurr);
//			dptrCurr += cn;
//		}
//	}
//}
//
//static void affineTransform8u(const uchar* sptr, int srcStep, int srcWidth, int srcHeight,
//	uchar* dptr, int dstStep, int dstWidth, int dstHeight, int cn, const float* xformCoeff)
//{
//	affineTransform_(sptr, srcStep, srcWidth, srcHeight, dptr, dstStep, dstWidth, dstHeight, cn, xformCoeff);
//}
//
//static void affineTransform8s(const schar* sptr, int srcStep, int srcWidth, int srcHeight,
//	schar* dptr, int dstStep, int dstWidth, int dstHeight, int cn, const float* xformCoeff)
//{
//	affineTransform_(sptr, srcStep, srcWidth, srcHeight, dptr, dstStep, dstWidth, dstHeight, cn, xformCoeff);
//}
//
//static void affineTransform16u(const ushort* sptr, int srcStep, int srcWidth, int srcHeight,
//	ushort* dptr, int dstStep, int dstWidth, int dstHeight, int cn, const float* xformCoeff)
//{
//	affineTransform_(sptr, srcStep, srcWidth, srcHeight, dptr, dstStep, dstWidth, dstHeight, cn, xformCoeff);
//}
//
//static void affineTransform16s(const short* sptr, int srcStep, int srcWidth, int srcHeight,
//	short* dptr, int dstStep, int dstWidth, int dstHeight, int cn, const float* xformCoeff)
//{
//	affineTransform_(sptr, srcStep, srcWidth, srcHeight, dptr, dstStep, dstWidth, dstHeight, cn, xformCoeff);
//}
//
//static void affineTransform32s(const int* sptr, int srcStep, int srcWidth, int srcHeight,
//	int* dptr, int dstStep, int dstWidth, int dstHeight, int cn, const float* xformCoeff)
//{
//	affineTransform_(sptr, srcStep, srcWidth, srcHeight, dptr, dstStep, dstWidth, dstHeight, cn, xformCoeff);
//}
//
//static void affineTransform32f(const float* sptr, int srcStep, int srcWidth, int srcHeight,
//	float* dptr, int dstStep, int dstWidth, int dstHeight, int cn, const float* xformCoeff)
//{
//	affineTransform_(sptr, srcStep, srcWidth, srcHeight, dptr, dstStep, dstWidth, dstHeight, cn, xformCoeff);
//}
//
//static void affineTransform64f(const double* sptr, int srcStep, int srcWidth, int srcHeight,
//	double* dptr, int dstStep, int dstWidth, int dstHeight, int cn, const float* xformCoeff)
//{
//	affineTransform_(sptr, srcStep, srcWidth, srcHeight, dptr, dstStep, dstWidth, dstHeight, cn, xformCoeff);
//}
//
//typedef void(*IvAffineTransformFunc)(const uchar* sptr, int srcStep, int srcWidth, int srcHeight,
//	uchar* dptr, int dstStep, int dstWidth, int dstHeight, int cn, const float* xformCoeff);
//
//static IvAffineTransformFunc gAffineTransformFuncTab[] =
//{
//	(IvAffineTransformFunc)affineTransform8u, (IvAffineTransformFunc)affineTransform8s,
//	(IvAffineTransformFunc)affineTransform16u, (IvAffineTransformFunc)affineTransform16s,
//	(IvAffineTransformFunc)affineTransform32s, (IvAffineTransformFunc)affineTransform32f,
//	(IvAffineTransformFunc)affineTransform64f,
//};
//
//void affineTransform(const cv::Mat& src, cv::Mat& dst, cv::Size dsize, const float* xformCoeff, bool isForward)
//{
//	float coeffDstToSrc[9] = { 0 };
//	if (isForward)
//	{
//		matrixInverse3x3(xformCoeff, coeffDstToSrc);
//	}
//	else
//	{
//		memcpy(coeffDstToSrc, xformCoeff, sizeof(*xformCoeff) * 9);
//	}
//
//	dst.create(dsize.area() == 0 ? src.size() : dsize, src.type());
//
//	IvAffineTransformFunc func = gAffineTransformFuncTab[src.depth()];
//	func(src.data, src.step, src.cols, src.rows,
//		dst.data, dst.step, dst.cols, dst.rows, src.channels(), coeffDstToSrc);
//}
//
//void rotate(const cv::Mat& src, cv::Mat& dst, cv::Size dsize, float angle, cv::Point2f center)
//{
//	float radian = angle * CV_PI / 180.0;
//	double sinVal = sin(radian);
//	double cosVal = cos(radian);
//	float xformCoeff[] =
//	{
//		cosVal, -sinVal, center.x - center.x * cosVal + center.y * sinVal,
//		sinVal, cosVal, center.y - center.x * sinVal - center.y * cosVal,
//		0, 0, 1
//	};
//	affineTransform(src, dst, dsize, xformCoeff, false);
//}

//int main()
//{
//	FILE  * fp1, * fp2, *fp3, *fp4;
//	//cv::Mat src = cv::imread("lena.jpg");
//	cv::Mat dst1(400,400,CV_8UC3, cv::Scalar(1)),
//		dst2(400,400, CV_32FC3,cv::Scalar(255)),
//		dst3(512, 512, CV_32FC1, cv::Scalar(0)),
//		dst4(512, 512, CV_8UC1, cv::Scalar(0));
//
//	//cv::imshow("src", src);
//	//rotate(src, dst, cv::Size(), 45, cv::Point2f(src.cols * 0.5f, src.rows * 0.5f));
//	//cv::imshow("dst 45", dst);
//	//rotate(src, dst, cv::Size(), 30, cv::Point2f(src.cols * 0.5f, src.rows * 0.5f));
//	//cv::imshow("dst 30", dst);
//	//cv::imwrite("dst_lena.jpg", dst);
//	//cv::waitKey();
//	//fp = fopen("src_lenaRGB.bin", "wb");
//	//fwrite(src.data, sizeof(uchar), 3 * src.rows * src.cols,fp);
//
//	//fp = fopen("dst_lenaRGB.bin", "wb");
//	//fwrite(dst.data, sizeof(uchar), 3 * dst.rows * dst.cols, fp);
//
//	fp1 = fopen("SrcImg_uchar_3_400_400.bin", "rb");
//	fp2 = fopen("SrcImg_float_3_400_400.bin", "wb");
//	fp3 = fopen("DstImg_float_1_512_512.bin", "rb");
//	fp4 = fopen("SrcImg_uchar_1_512_512.bin", "wb");
//	fread(dst1.data, sizeof(uchar)*3, 400 * 400, fp1);
//	
//	fread(dst2.data, sizeof(float), 400 * 400, fp2);
//
//	/*uchar a[4 * 512 * 512] = { 0 };
//	dst_float.data = a;*/
//	for (int i = 0;i < dst1.rows;i++) {
//		for (int j = 0;j < dst1.cols*3;j++) {
//			dst2.at<float>(i, j) = dst1.at<uchar>(i, j);
//		}
//	}
//	fread(dst3.data, sizeof(float), 512 * 512, fp3);
//	for (int i = 0;i < dst3.rows;i++) {
//		for (int j = 0;j < dst3.cols;j++) {
//			dst4.at<uchar>(i, j) = (uchar)dst3.at<float>(i, j);
//		}
//	}
//	fwrite(dst4.data, sizeof(uchar), 512 * 512, fp4);
//	fclose(fp1);
//	fclose(fp2);
//	fclose(fp3);
//	fclose(fp4);
//	return 0;
//}

//#include <opencv2/opencv.hpp>
//#define WIDTH 400
//#define HEIGHT 400
//using namespace cv;
//using namespace std;
//
//int main()
//{
//	Mat src = imread("lena.jpg", 1);
//	FILE *fp;
//
//	namedWindow("RGB", WINDOW_AUTOSIZE);
//	imshow("RGB", src);
//
//	const int channels = src.channels();
//
//	MatIterator_<Vec3b> it, end;
//	unsigned char dst_data[WIDTH * 3 * HEIGHT];
//	int nRows = src.rows;
//	int nCols = src.cols*channels;
//
//	int i, j;
//	uchar* p;
//	for (i = 0; i < nRows; ++i)
//	{
//		p = src.ptr<uchar>(i);
//		for (j = 0; j < nCols; j += 3)
//		{
//			dst_data[i * nCols + j] = p[j];
//			dst_data[i * nCols + j + 1] = p[j + 1];
//			dst_data[i * nCols + j + 2] = p[j + 2];
//		}
//	}
//	fp = fopen("LenaRGB.bin", "wb");
//	fwrite(dst_data, sizeof(char), WIDTH * 3 * HEIGHT, fp);
//	waitKey(0);
//	src.release();
//	destroyWindow("RGB");
//	return 0;
//}


//#include "Core.h"
//
//using namespace std;
//
//int main()
//{
//	Core::PictureCopy();
//	return 0;
//}

//#include <opencv2/opencv.hpp>
//#include <iostream>
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	Mat image = imread("D:\\Picture\\timg.jpg");  //存放自己图像的路径 
//	imshow("显示图像", image);
//	waitKey(0);
//	return 0;
//}

//#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imgproc/imgproc.hpp"
//#include <iostream>
//#include <stdio.h>
//
//using namespace cv;
//using namespace std;
//
//int main(int argc, char** argv)
//{
//	Mat src, dst;
//	const char* source_window = "Source image";
//	const char* equalized_window = "Equalized Image";
//	src = imread("D:\\Picture\\timg.jpg");
//
//	if (!src.data)
//	{
//		cout << "Usage: ./Histogram_Demo <path_to_image>" << endl;
//		return -1;
//	}
//
//	/// 转为灰度图,原地转换
//	cvtColor(src, src, CV_BGR2GRAY);
//
//	/// 应用直方图均衡化
//	equalizeHist(src, dst);
//
//	/// 显示结果
//	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
//	namedWindow(equalized_window, CV_WINDOW_AUTOSIZE);
//
//	imshow(source_window, src);
//	imshow(equalized_window, dst);
//
//	/// 等待用户按键退出程序
//	waitKey(0);
//	system("pause");
//	return 0;
//}

#include"Core.h"

int main(int argc, char **argv)
{
	
	Core::HelloWorld();
	return 0;
}
