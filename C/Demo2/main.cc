#include<stdio.h>
#include<sys/time.h>

#define TIME_BEGIN(begin,end) struct timeval begin, end; double timeuse; gettimeofday(&begin,NULL);
#define TIME_END(begin,end) gettimeofday(&end,NULL); timeuse=1000000 * (end.tv_sec - begin.tv_sec) + end.tv_usec - begin.tv_usec;

void sleep(long n){
	int a=0;
	for(long i=0; i < n; i++) {
		a++;
		printf("%d ",a);
	}
	printf("\n");
}

void test_time(){
	TIME_BEGIN(begin,end)
	sleep(40);
	TIME_END(begin,end)
	printf("Used time:%fus\n", timeuse);
}

int main(int argc,char* argv[]){
	printf("Begin!\n");
	test_time();
	printf("End!\n");
	return 0;
}
