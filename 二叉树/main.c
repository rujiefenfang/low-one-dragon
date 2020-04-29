#include"LinkTree.h"
int main()
{
	printf("1.创建二叉树\n2.前缀计算器\n0.结束\n");
	printf("请输入你的指令：");
	int num;
	while(scanf("%d",&num)&&num!=0){
		fflush(stdin);
		if(num==1){
			BiTNode *T;
			InitBiTree(&T);
			char a[30];
			int i;
			printf("请输入你要创建的二叉树  例如:1(1(2,3),3(2,3))\n"); 
			gets(a);
			CreateBiTree(&T, a);
			printf("先序遍历：\n"); 
			PreOrderTraverse(T,visit);
			printf("\n中序遍历：\n"); 
			InOrderTraverse(T,visit);
			printf("\n后序遍历：\n"); 
			PostOrderTraverse(T,visit);
			printf("\n层序遍历：\n"); 
			LevelOrderTraverse(T,visit);
			printf("\n非递归前序\n");
			preorderTraverse_1(T);
			printf("\n非递归中序\n");
			InOrderTraverse_1(T); 
			printf("\n非递归后序\n");
			PostOrderTraverse_1(T);
			DestroyBiTree(T);
			T=NULL;
			printf("\n");
		}
		if(num==2){
			BiTNode *t;
			InitBiTree(&t);
			char b[20];
			printf("输入前缀表达式："); 
			gets(b);
			int i=0;
			creat(&t,b,&i);
			float val=Value(t);
			printf("\n结果是%f\n",val);
			DestroyBiTree(t);
			t=NULL;
		}
		printf("请重新输入指令："); 
		
}
	
}


