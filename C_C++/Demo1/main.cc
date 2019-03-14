#include<stdio.h>
 #include<sys/time.h>

void sleep(long n){
	int a=0;
	for(long i=0; i < n; i++) {
		a++;
		printf("%d",a);
	}
}

void test_time(){
	
	//struct timeval {
	//long tv_sec;	/* seconds */
	//long tv_usec; /* and microseconds */
	//};
	struct timeval tpstart, tpend;
	double timeuse;
	gettimeofday(&tpstart,NULL);
	sleep(40);
	gettimeofday(&tpend,NULL);
	timeuse=1000000 * (tpend.tv_sec - tpstart.tv_sec) 
		+ tpend.tv_usec - tpstart.tv_usec;
	printf("Used time:%fus\n", timeuse);
}

int main(int argc,char* argv[]){
	printf("Begin!\n");
	test_time();
	printf("End!\n");
	return 0;
}
