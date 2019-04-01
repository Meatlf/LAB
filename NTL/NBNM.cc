#include<omp.h>
#include<NTL/ZZ.h>
#include<cstdlib>
#include<ctime>
using namespace std;
using namespace NTL;

int main(){
	clock_t t1,t2;
	t1=clock();
	Vec x[8],y[8],z[8];
	long l=32768*64;
	RandomBits(x[0],l);
	RandomBits(y[0],l);
	
	z=x[0]*y[0];
	
	
	t2=clock();cout<<(double)(t2-t1)/CLOCKS_PER_SEC<<endl;
}
