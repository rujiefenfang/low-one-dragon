#include"LQueue.h"
//初始化 
void InitLQueue(LQueue *Q){
	Node *p=(Node*)malloc(sizeof(Node));//这里定义头节点无数据 
	p->next=NULL;
	Q->front=Q->rear=p;
	Q->length=0;
	if(p!=NULL) printf("初始化成功\n");
	else printf("初始化失败\n");
}

//销毁队列
void DestoryLQueue(LQueue *Q)
{	
	if(Q->length==0) return; 
	ClearLQueue(Q);
	free(Q->front);         
	Q->front=NULL;
 }
 
//判空 
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->front->next==NULL) return 1;
	else return 0;
}
//得到头队列元素
Status GetHeadLQueue(LQueue *Q, void *e){
	memcpy(e,Q->front->next->data,size(Q->front->next->type)); //队头元素赋给e 
} 
//链队列的长度
int LengthLQueue(LQueue *Q){
	return Q->length;
} 
//入队 type为数据类型，数字代表 1-整型，2-字符型 ，3-浮点型 ，4-字符串 
Status EnLQueue(LQueue *Q, void *data,int type){
	Node *p=(Node*)malloc(sizeof(Node));
	p->data=(void*)malloc(size(type));       
	memcpy(p->data,data,size(type));
	Q->rear->next=p;                  //新创建节点与对尾连接 
	Q->rear=p;                       //对位指向新创建的节点 
	Q->rear->type=type;
	p->next=NULL;
	Q->length++;	//长度加一 
}
//出列
Status DeLQueue(LQueue *Q){
	Node *p;
	p=Q->front->next;
	Q->front->next=p->next;
	free(p->data);      
	free(p);
	Q->length--;
	if(Q->length==0) p->rear=p->front;
}
//清空链队列 
void ClearLQueue(LQueue *Q){
	Node *p1,*p2;
	p1=Q->front->next;
	while(Q->front->next!=NULL){
		Q->front->next=p1->next;
		free(p1->data);          //清空数据 
		free(p1);         //清空节点 
		p1=Q->front->next; 
	}
	Q->rear=Q->front;  //头尾相接 
	Q->length=0; //长度置0 
}
//遍历队列
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,int type))
{
	Node *p;
	p=Q->front->next;
	while(p!=NULL){
		foo(p->data,p->type); //输出元素 
		p=p->next;
	}
	printf("\n"); 
} 
//打印type为数据类型，数字代表 1-整型，2-字符型 ，3-浮点型 ，4-字符串
void LPrint(void *q,int type){
	switch(type){
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
	}
} 
//type对应数据类型字节数，type为数据类型，数字代表 1-整型，2-字符型 ，3-浮点型 ，4-字符串 
int size(int type){
		switch(type){
		case 1:
			return(sizeof(int));
			break;
		case 2:
			return(sizeof(char));
			break;
		case 3:
			return(sizeof(double));
			break;
		case 4:
			return(sizeof(char)*20);
	}
} 
//输入函数
void push(LQueue *Q){
	printf("请输入你要插入的数据类型：\n");
	printf("1.整型 2.字符型 3.浮点型 4.字符串(最大长度不超多20)\n");
	int i;
	scanf("%d",&i);
	printf("请输入你的数据："); 
		switch(i){	
		case 1:{ 
			int a;
			scanf("%d",&a); 
			EnLQueue(Q, &a,i);
			Q->rear->type=i;
			break;
		} 
		case 2:{ 
			char a;
			fflush(stdin); 
			scanf("%c",&a);
			EnLQueue(Q, &a,i);
			Q->rear->type=i;
			break;
	   } 
		case 3:{ 
			double a;
			scanf("%lf",&a);
			EnLQueue(Q, &a,i);
			Q->rear->type=i;
			break;
		} 
		case 4:{ 
			char a[20];
			scanf("%s",a);
			EnLQueue(Q, a,i);
			Q->rear->type=i;
			break;
		}		 
}
}
//输入头队列元素 
void gethead(LQueue *q,int j){
	switch(j){
		case 1:{
			int ch;
			GetHeadLQueue(q,&ch);
			LPrint(&ch,1); 
			break;
		}
		case 2:{
			char ch;
			GetHeadLQueue(q,&ch);
			LPrint(&ch,2);
			break;
		}
		case 3:{
			double ch;
			GetHeadLQueue(q,&ch);
			LPrint(&ch,3);
			break;
		}
		case 4:{
			char ch[20];
			GetHeadLQueue(q,ch);
			LPrint(ch,4);
			break;
		}
	}
	printf("\n");
}
//屏幕显示
void screen()
{
	printf("\t\t\t***************************************************************\t\n"
	       "\t\t\t**-----------1.初始化队列------------------------------------**\t\n"
	       "\t\t\t**-----------2.销毁队列--------------------------------------**\t\n"
		   "\t\t\t**-----------3.队列判空--------------------------------------**\t\n"
		   "\t\t\t**-----------4.输出头队列元素--------------------------------**\t\n"
		   "\t\t\t**-----------5.队列长度--------------------------------------**\t\n"
		   "\t\t\t**-----------6.入队------------------------------------------**\t\n"
		   "\t\t\t**-----------7.出队------------------------------------------**\t\n"
		   "\t\t\t**-----------8.清空队列--------------------------------------**\t\n"
		   "\t\t\t**-----------9.遍历队列--------------------------------------**\t\n"
		   "\t\t\t**-----------0.退出程序(注意先销毁队列）---------------------**\t\n"
		   "\t\t\t***************************************************************\t\n");
 } 

