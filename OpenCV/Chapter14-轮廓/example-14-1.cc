#include <opencv2/opencv.hpp>
#include <iostream>

cv::Mat g_gray, g_binary;

int g_thresh = 100;

void on_trackbar(int, void*){
    cv::threshold(g_gray,g_binary,g_thresh,255,cv::THRESH_BINARY);
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(g_binary,contours,cv::noArray(),cv::RETR_LIST,cv::CHAIN_APPROX_SIMPLE);
    g_binary = cv::Scalar::all(0);

    cv::draw();
}