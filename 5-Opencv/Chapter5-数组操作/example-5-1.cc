#include<opencv2/opencv.hpp>
#include<iostream>

int main(int argc, char** argv){
    cv::Mat src1 = cv::imread(argv[1],1);
    cv::Mat src2 = cv::imread(argv[2],1);

    if(argc == 9 && !src1.empty() && !src2.empty()){
        int x = atoi(argv[3]);
        int y = atoi(argv[4]);
        int w = atoi(argv[5]);
        int h = atoi(argv[6]);
        double alpha = (double)atof(argv[7]);
        double beta = (double)atof(argv[8]);

        cv::Mat roi1(src1, cv::Rect(x,y,w,h));
        cv::Mat roi2(src2, cv::Rect(0,0,w,h));

        cv::addWeighted(roi1,alpha,roi2,beta,0.0,roi1);

        cv::namedWindow("Alpha Blend",1);
        cv::imshow("Alpha Blend",src1);
        cv::waitKey(0);
    }
    return 0;
}