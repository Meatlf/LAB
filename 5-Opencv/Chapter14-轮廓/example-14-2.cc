/*
输入图像的轮廓,然后逐个绘制每条轮廓
*/
#include <opencv2/opencv.hpp>
#include <iostream>
#include <iostream>

struct AreaCmp
{
    AreaCmp(const std::vector<float>& _areas) : areas(&_areas) {}
    bool operator()(int a, int b) const {return (*areas)[a] > (*areas)[b];}
    const std::vector<float>* areas;
};

int main( int argc, char** argv ) {
	
	if (argc != 2 || (img = cv::imread(argv[1], cv::LOAD_IMAGE_GRAYSCALE)).empty()) {
        std::cout << "Can't load image!!!" << std::endl;
		return -1;
	}

    cv::threshold(img, img_edge, 128, 255, cv::THRESH_BINARY);
    cv::imshow("Image after threshold", img_edge);
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    cv::findContours(
        img_edge,
        contours,
        hierarchy,
        cv::RETR_LIST,
        cv::CHAIN_APPROX_SIMPLE
    );

    std::vector<int> sortIdx(contours.size());
    for(int n = 0; n < (int)contours.size(); n++){
        sortIdx[n] = n;
        areas[n] = contourArea(contours[n], false);
    }

    // sort contours so that the largest contours go first
    std::sort();

    for(int n = 0; n < (int)sortIdx.size(); n++){

    }
  return 0;
}
