/*
检测轮廓,画出轮廓
*/
#include <opencv2/opencv.hpp>
#include <iostream>

int main( int argc, char** argv ) {
	
	if (argc != 2) {
		return 0;
	}
		
  cv::Mat srcImg = cv::imread( argv[1], -1 );
  cv::Mat grayImg;
  std::vector<std::vector<cv::Point>> contours;

  if( srcImg.empty() ) return -1;

  cv::Mat binaryImg;

  cv::cvtColor(srcImg, grayImg, cv::COLOR_BGR2GRAY);
  cv::threshold(grayImg, binaryImg, 100, 255, cv::THRESH_BINARY);
  
//   cv::findContours(binaryImg, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
//   cv::findContours(binaryImg, contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);
//   cv::findContours(binaryImg, contours, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
  cv::findContours(binaryImg, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

  cv::drawContours(srcImg, contours, -1, cv::Scalar(0,255,0,0));

  cv::imshow(argv[1], srcImg);

  // Idle until the user hits any key.
  cv::waitKey(0);
  return 0;
}
