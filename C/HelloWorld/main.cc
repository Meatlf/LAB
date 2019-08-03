#include<iostream>

// Limit x to [minValue, maxValue]
#define CLIP3(x, minValue, maxValue)	((x) > (maxValue) ? (maxValue) : ((x) < (minValue) ? (minValue) : (x)))

int add_a_and_b(int a, int b){
	return a + b;
}

int main() {
	std::cout << CLIP3(16, 12, 20);
	return add_a_and_b(3,4);
}