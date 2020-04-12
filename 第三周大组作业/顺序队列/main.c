#include "AQueue.h"
int main()
{
	AQueue q;
	q.data[0]=NULL;
	int i,j=0;
	screen();
	while(printf("请输入指令：\n")&&scanf("%d",&i)&&i!=0)
	{
		j++;
		if(j%5==0) screen();
		if(i==1){
			InitAQueue(&q);
			printf("初始化成功!\n");
		}
		if(i==2){
			if(q.data[0]==NULL) {
				printf("队列未初始化\n");
				continue; 
			} 
			IsEmptyAQueue(&q);					
		} 
		if(i==3){
			if(q.data[0]==NULL) {
				printf("队列未初始化\n");
				continue; 
			} 
			IsFullAQueue(&q);			
		}
		if(i==4){
		  //这是一个输入函数
		  	if(q.data[0]==NULL) {
				printf("队列未初始化\n");
				continue; 
			}			
			push(&q);		 						
		}
		if(i==5){
			//输出头队列元素
			if(q.data[0]==NULL) {
				printf("队列未初始化\n");
				continue; 
			}
			if(q.length==0){
				printf("队列为空\n");
				continue; 
			}
			int k=q.type[q.front];
			gethead(q,k);
			printf("\n"); 
		}
		if(i==6){//队列长度 
			if(q.data[0]==NULL) {
				printf("队列未初始化\n");
				continue; 
			}
			printf("队列长度为%d\n",LengthAQueue(&q));
		}
		if(i==7){//出队 
			if(q.data[0]==NULL) {
				printf("队列未初始化\n");
				continue; 
			}
			if(DeAQueue(&q)) printf("出队成功\n");
			else printf("队列为空或者未初始化\n"); 
		}
		if(i==8){//清空队列 
			ClearAQueue(&q);
			printf("\n");
		}
		if(i==9){//遍历队列 
			if(q.data[0]==NULL) {
				printf("队列未初始化\n");
				continue; 
			}
			TraverseAQueue(&q, APrint);
		}
		if(i==10){//销毁队列 
			DestoryAQueue(&q);
	}
	if(j%5==0&&q.data[0]!=NULL) printf("队列的长度为%d,还剩%d个空间\n",q.length,MAXQUEUE-q.length);
	}
}
