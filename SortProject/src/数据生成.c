#include "../inc/qgsort.h"
int main()
{
	printf("随机生成了数据，并保存到data.txt文件中\n");
	printf("请输入数据的的范围上界(下界为0)\n");
	int j;
	scanf("%d",&j);
	FILE *fpWrite = fopen("../src/data.txt","w");
	if(fpWrite==NULL) return 0;
	int i,n;
	printf("请输入数据规模：");
	scanf("%d",&n); 
	int a[n];
	for(i=0;i<n;i++){
		rand();
		a[i]=rand()%j;
		fprintf(fpWrite,"%d ",a[i]);
	}
	fclose(fpWrite);
	printf("生成成功\n");
	printf("输入0退出\n"); 
	scanf("%d",&j); 
}
