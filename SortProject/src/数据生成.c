#include "../inc/qgsort.h"
int main()
{
	printf("������������ݣ������浽data.txt�ļ���\n");
	printf("���������ݵĵķ�Χ�Ͻ�(�½�Ϊ0)\n");
	int j;
	scanf("%d",&j);
	FILE *fpWrite = fopen("../src/data.txt","w");
	if(fpWrite==NULL) return 0;
	int i,n;
	printf("���������ݹ�ģ��");
	scanf("%d",&n); 
	int a[n];
	for(i=0;i<n;i++){
		rand();
		a[i]=rand()%j;
		fprintf(fpWrite,"%d ",a[i]);
	}
	fclose(fpWrite);
	printf("���ɳɹ�\n");
	printf("����0�˳�\n"); 
	scanf("%d",&j); 
}
