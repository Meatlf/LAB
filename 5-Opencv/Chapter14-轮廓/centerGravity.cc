/*
@brief 求任意点的重心
*/
#include<iostream>

struct coordinate
{
    /* data */
    int x;
    int y;
};

coordinate centerGravity(coordinate* counter, int count)
{
    coordinate centerGravityValue;
    int xSum  = 0, ySum = 0;
    for(int i=0;i<count;i++)
    {
        xSum+=counter[i].x;
        ySum+=counter[i].y;
    }
    centerGravityValue.x=xSum/count;
    centerGravityValue.y=ySum/count;
    return centerGravityValue;
}

void centerGravity_test()
{
    int count = 4;
    coordinate* counter = (coordinate*)malloc(sizeof(coordinate) * count);
    counter[0].x=0;
    counter[0].y=0;
    counter[1].x=2;
    counter[1].y=0;
    counter[2].x=2;
    counter[2].y=2;
    counter[3].x=0;
    counter[3].y=2;

    coordinate centerGravityValue;
    centerGravityValue = centerGravity(counter,count);
    std::cout << centerGravityValue.x << std::endl;
    std::cout << centerGravityValue.y << std::endl;
}

int main()
{
    centerGravity_test();
    return 0;
}
