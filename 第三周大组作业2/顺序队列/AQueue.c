#include "AQueue.h"

//初始化队列
void InitAQueue(AQueue *Q)
{	
	int i;
	Q->front=0;
	Q->rear=0;
	Q->length=0;
	for(i=0;i<MAXQUEUE;i++) //不知数据类型 ，假定给20个字节 
		Q->data[i]=(void*)malloc(20);
}	

//销毁队列
void DestoryAQueue(AQueue *Q)
{
	 if(Q->data[0]==NULL){
	 	printf("队列未初始化\n"); 
	 }
	else {
		int i;
		for(i=0;i<10;i++)
		 	free(Q->data[i]);
		Q->data[0]=NULL;
		printf("销毁成功\n");
	}
 }
 
//队列判满 
Status IsFullAQueue(const AQueue *Q)
{	
	if(Q->length==MAXQUEUE-1)   printf("队列满了\n");
	else  printf("队列未满\n");

} 
//队列判空 
Status IsEmptyAQueue(const AQueue *Q){
	
	if(Q->length==0)  printf("队列是空的\n");
	else  printf("队列不为空\n");
	
}
//查看队头元素
Status GetHeadAQueue(AQueue *Q, void *e)
{	
	memcpy(e,Q->data[Q->front], 20);  	
}
//队列长度 
int LengthAQueue(AQueue *Q)
{
	return Q->length;
 }
// 入队 
Status EnAQueue(AQueue *Q, void *data)
{
	if(Q->length==MAXQUEUE-1) return 0;
	else
	{ 	
		memcpy(Q->data[Q->rear], data, 20);
		Q->rear=(Q->rear+1)%MAXQUEUE;
		Q->length++;
		return 1;
	}
}
//出队 
Status DeAQueue(AQueue *Q)
{
	if(Q->length==0) return 0; 
	else
	{
		Q->front=(Q->front+1)%MAXQUEUE;
		Q->length--;
		return 1;
	} 
}
//清空队列 
void ClearAQueue(AQueue *Q)
{
	Q->front=Q->rear=Q->length=0;
	printf("清空成功\n"); 
} 
//遍历元素 
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q,int type))
{
	if(Q->length==0) printf("队列为空\n"); 
	else{
		printf("各个元素为："); 
		int i = 0;
    	while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
    		foo(Q->data[Q->front+i], Q->type[Q->front+i]);
    		i = (i + 1) % MAXQUEUE;		
	}
	printf("\n"); 
}	 
} 
//输出元素 
void APrint(void *q,int type){

	switch(type)
	{
		case 1:
			printf("%d ",*(int*)q);
			break;
		case 2:
			printf("%c ",*(char*)q);
			break;
		case 3:
			printf("%f ",*(double*)q);
			break;
		case 4:
			printf("%s ",(char*)q);
			break;
	}	
}
//将数据输入到队尾 
void push(AQueue *Q){
	printf("请输入你要插入的数据类型：\n");
	printf("1.整型 2.字符型 3.浮点型 4.字符串(最大长度不超多20)\n");
	int i;
	scanf("%d",&i);
	while(i<1||i>4){
		printf("请输入正确指令："); 
		scanf("%d",&i);
	}
	printf("请输入你的数据："); 
		switch(i){	
		case 1:{ 
			int a;
			scanf("%d",&a);
			Q->type[Q->length]=i;
			EnAQueue(Q, &a);
			break;
		} 
		case 2:{ 
			char a;
			fflush(stdin);
			scanf("%c",&a);
			Q->type[Q->length]=i;
			EnAQueue(Q, &a);
			break;
	   } 
		case 3:{ 
			double a;
			scanf("%lf",&a);
			Q->type[Q->length]=i;
			EnAQueue(Q, &a);
			break;
		} 
		case 4:{ 
			char a[20];
			scanf("%s",a);
			Q->type[Q->length]=i;
			EnAQueue(Q, a);
			break;
		}		 
}
}
//屏幕显示 
void screen()
{
	printf("\t\t\t***************************************************************\t\n"
	       "\t\t\t**-----------1.初始化队列------------------------------------**\t\n"
	       "\t\t\t**-----------2.队列判空--------------------------------------**\t\n"
		   "\t\t\t**-----------3.队列判满--------------------------------------**\t\n"
		   "\t\t\t**-----------4.入队------------------------------------------**\t\n"
		   "\t\t\t**-----------5.输出头队列元素--------------------------------**\t\n"
		   "\t\t\t**-----------6.队列长度--------------------------------------**\t\n"
		   "\t\t\t**-----------7.出队------------------------------------------**\t\n"
		   "\t\t\t**-----------8.清空队列--------------------------------------**\t\n"
		   "\t\t\t**-----------9.遍历队列--------------------------------------**\t\n"
		   "\t\t\t**-----------10.销毁队列-------------------------------------**\t\n"
		   "\t\t\t**-----------0.退出程序(注意先销毁队列）---------------------**\t\n"
		   "\t\t\t***************************************************************\t\n");
}
//输出队头元素 
void gethead(AQueue q,int type){ 
	printf("队头元素为："); 
 	switch(type){
		case 1:{
			int ch;
			GetHeadAQueue(&q, &ch);
			APrint(&ch,q.type[q.front]);
			break;			
		}
		case 2:{
			char ch;
			GetHeadAQueue(&q, &ch);
			APrint(&ch,q.type[q.front]);
			break;
		}
		case 3:{
			double ch;				
			GetHeadAQueue(&q, &ch);
			APrint(&ch,q.type[q.front]);
			break;
		}
		case 4:{
			char ch[20];
			GetHeadAQueue(&q, ch);
			APrint(ch,q.type[q.front]);
			break;
		}
 }
 }


