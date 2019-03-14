#include<stdio.h>
#include<sys/time.h>

void sleep(int a){
	for(int i=0; i < a; i++)
		i;
}

void test_time(){
	
	//struct timeval {
	//long tv_sec;	/* seconds */
	//long tv_usec; /* and microseconds */
	//};
	struct timeval tpstart, tpend;
	double timeuse;
	gettimeofday(&tpstart,NULL);
	sleep(1000000000);
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
