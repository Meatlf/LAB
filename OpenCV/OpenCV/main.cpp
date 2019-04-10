//#include <opencv2/opencv.hpp>
//#include <iostream>
//using namespace std;
//using namespace cv;
//
//int main()
//{
//	Mat image = imread("D:\\Picture\\timg.jpg");  //����Լ�ͼ���·�� 
//	imshow("��ʾͼ��", image);
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
//	/// תΪ�Ҷ�ͼ,ԭ��ת��
//	cvtColor(src, src, CV_BGR2GRAY);
//
//	/// Ӧ��ֱ��ͼ���⻯
//	equalizeHist(src, dst);
//
//	/// ��ʾ���
//	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
//	namedWindow(equalized_window, CV_WINDOW_AUTOSIZE);
//
//	imshow(source_window, src);
//	imshow(equalized_window, dst);
//
//	/// �ȴ��û������˳�����
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
		cout << "��ͼ��ʧ�ܣ�" << endl;
		return -1;
	}
	namedWindow("image", CV_WINDOW_AUTOSIZE);
	imshow("image", img);
	waitKey();

	return 0;
}
