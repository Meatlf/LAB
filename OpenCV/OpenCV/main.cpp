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

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
	Mat img = imread("lena.jpg");
	if (img.empty())
	{
		cout << "打开图像失败！" << endl;
		return -1;
	}
	namedWindow("image", CV_WINDOW_AUTOSIZE);
	imshow("image", img);
	waitKey();

	return 0;
}
