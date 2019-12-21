/*
查找轮廓的第一个非0点

成功使用OpenCV的源码
*/
#include <opencv2/core/types_c.h>
#include <iostream>

inline int findStartContourPoint(std::vector<u_char> src_data, CvSize img_size, int j)
{
    for(; j < img_size.width && !src_data[j]; ++j)
        ;
    return j;
}

int main(int argc, char** argv){
    std::vector<u_char> src_data;
    src_data.push_back(0);
    src_data.push_back(0);
    src_data.push_back(66);
    src_data.push_back(4);
    src_data.push_back(1);
    cv::Size img_size(7,2);

    std::cout << findStartContourPoint(src_data, cvSize(img_size), 0) << std::endl;
    return 0;
}