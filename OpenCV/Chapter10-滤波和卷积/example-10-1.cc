#include<opencv2/opencv.hpp>
#include<iostream>

void sum_rgb(const cv::Mat& src, cv::Mat& dst){
    // Split image onto the color planes.
    //
    std::vector<cv::Mat> planes;
    cv::split(src, planes);

    cv::Mat b = planes[0], g = planes[1], r = planes[2], s;

    // Add equally weighted rgb values.
    //
    cv::addWeighted(r, )
}
