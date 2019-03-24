#include<stdio.h>
#include<sys/time.h>

#define TIME_BEGIN struct timeval tpstart, tpend; double timeuse; gettimeofday(&tpstart,NULL);
#define TIME_END gettimeofday(&tpend,NULL); timeuse=1000000 * (tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;

void sleep(long n){
	int a=0;
	for(long i=0; i < n; i++) {
		a++;
		printf("%d ",a);
	}
	printf("\n");
}

void test_time(){
	TIME_BEGIN
	sleep(40);
	TIME_END
	printf("Used time:%fus\n", timeuse);
}

int main(int argc,char* argv[]){
	printf("Begin!\n");
	test_time();
	printf("End!\n");
	return 0;
}
