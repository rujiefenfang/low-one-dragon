#include"LinkTree.h"
int main()
{
	printf("1.����������\n2.ǰ׺������\n0.����\n");
	printf("���������ָ�");
	int num;
	while(scanf("%d",&num)&&num!=0){
		fflush(stdin);
		if(num==1){
			BiTNode *T;
			InitBiTree(&T);
			char a[30];
			int i;
			printf("��������Ҫ�����Ķ�����  ����:1(1(2,3),3(2,3))\n"); 
			gets(a);
			CreateBiTree(&T, a);
			printf("���������\n"); 
			PreOrderTraverse(T,visit);
			printf("\n���������\n"); 
			InOrderTraverse(T,visit);
			printf("\n���������\n"); 
			PostOrderTraverse(T,visit);
			printf("\n���������\n"); 
			LevelOrderTraverse(T,visit);
			printf("\n�ǵݹ�ǰ��\n");
			preorderTraverse_1(T);
			printf("\n�ǵݹ�����\n");
			InOrderTraverse_1(T); 
			printf("\n�ǵݹ����\n");
			PostOrderTraverse_1(T);
			DestroyBiTree(T);
			T=NULL;
			printf("\n");
		}
		if(num==2){
			BiTNode *t;
			InitBiTree(&t);
			char b[20];
			printf("����ǰ׺���ʽ��"); 
			gets(b);
			int i=0;
			creat(&t,b,&i);
			float val=Value(t);
			printf("\n�����%f\n",val);
			DestroyBiTree(t);
			t=NULL;
		}
		printf("����������ָ�"); 
		
}
	
}


