#include<opencv2/opencv.hpp>
#include<iostream>

void sum_rgb(const cv::Mat& src, cv::Mat& dst){
    // Split image onto the color planes.
    std::vector<cv::Mat> planes;
    cv::split(src, planes);

    cv::Mat b = planes[0], g = planes[1], r = planes[2], s;

    // Add equally weighted rgb values.
    cv::addWeighted(r, 1./3., g, 1./3., 0.0, s);
    cv::addWeighted(s, 1., b, 1./3., 0.0, s);

    // Truncate values above 100.
    // cv::threshold(s, dst, 100, 100, cv::THRESH_TRUNC);
    // cv::threshold(s, dst, 100, 255, cv::THRESH_BINARY_INV);
    cv::threshold(s, dst, 100, 255, cv::THRESH_TOZERO_INV);
}

void help(){
    std::cout << "faceScene.jpg" << std::endl;
    std::cout << "Show use of alpha blending (addWeighted) and threshold" << std::endl;
}

int main(int argc, char** argv){
    help();
    if(argc < 2){std::cout << "specify input image" << std::endl; return -1;}

    // Load the image from the given file name.
    cv::Mat src = cv::imread(argv[1]), dst;
    if(src.empty()) {std::cout << "can not load" << argv[1] << std::endl; return -1;}
    sum_rgb(src, dst);

    // Create a named window with the name of the file and 
    // show the image in the window
    cv::imshow(argv[1], dst);

    // Idle until the user hits any key.
    cv::waitKey(0);
    return 0;
}
