#include "qgsort.h"
int main()
{	
	printf("����������0-1000\n");
	int n=20000;
	printf("******************20000size*********************\n");
	time1(n);
	n=50000;
	printf("******************50000size*********************\n");
	time1(n);
	n=200000;
	printf("******************200000size********************\n");
	time1(n);
	printf("******************100k*100**********************\n");
	time2();
}
