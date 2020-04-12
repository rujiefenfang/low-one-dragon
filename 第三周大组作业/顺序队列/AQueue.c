#include "AQueue.h"

//��ʼ������
void InitAQueue(AQueue *Q)
{	
	int i;
	Q->front=0;
	Q->rear=0;
	Q->length=0;
	for(i=0;i<MAXQUEUE;i++) //��֪�������� ���ٶ���20���ֽ� 
		Q->data[i]=(void*)malloc(20);
}	

//���ٶ���
void DestoryAQueue(AQueue *Q)
{
	 if(Q->data[0]==NULL){
	 	printf("����δ��ʼ��\n"); 
	 }
	else {
		int i;
		for(i=0;i<10;i++)
		 	free(Q->data[i]);
		Q->data[0]=NULL;
		printf("���ٳɹ�\n");
	}
 }
 
//�������� 
Status IsFullAQueue(const AQueue *Q)
{	
	if(Q->length==MAXQUEUE-1)   printf("��������\n");
	else  printf("����δ��\n");

} 
//�����п� 
Status IsEmptyAQueue(const AQueue *Q){
	
	if(Q->length==0)  printf("�����ǿյ�\n");
	else  printf("���в�Ϊ��\n");
	
}
//�鿴��ͷԪ��
Status GetHeadAQueue(AQueue *Q, void *e)
{	
	memcpy(e,Q->data[Q->front], 20);  	
}
//���г��� 
int LengthAQueue(AQueue *Q)
{
	return Q->length;
 }
// ��� 
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
//���� 
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
//��ն��� 
void ClearAQueue(AQueue *Q)
{
	Q->front=Q->rear=Q->length=0;
	printf("��ճɹ�\n"); 
} 
//����Ԫ�� 
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q,int type))
{
	if(Q->length==0) printf("����Ϊ��\n"); 
	else{
		printf("����Ԫ��Ϊ��"); 
		int i = 0;
    	while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
    		foo(Q->data[Q->front+i], Q->type[Q->front+i]);
    		i = (i + 1) % MAXQUEUE;		
	}
	printf("\n"); 
}	 
} 
//���Ԫ�� 
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
//���������뵽��β 
void push(AQueue *Q){
	printf("��������Ҫ������������ͣ�\n");
	printf("1.���� 2.�ַ��� 3.������ 4.�ַ���(��󳤶Ȳ�����20)\n");
	int i;
	scanf("%d",&i);
	while(i<1||i>4){
		printf("��������ȷָ�"); 
		scanf("%d",&i);
	}
	printf("������������ݣ�"); 
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
//��Ļ��ʾ 
void screen()
{
	printf("\t\t\t***************************************************************\t\n"
	       "\t\t\t**-----------1.��ʼ������------------------------------------**\t\n"
	       "\t\t\t**-----------2.�����п�--------------------------------------**\t\n"
		   "\t\t\t**-----------3.��������--------------------------------------**\t\n"
		   "\t\t\t**-----------4.���------------------------------------------**\t\n"
		   "\t\t\t**-----------5.���ͷ����Ԫ��--------------------------------**\t\n"
		   "\t\t\t**-----------6.���г���--------------------------------------**\t\n"
		   "\t\t\t**-----------7.����------------------------------------------**\t\n"
		   "\t\t\t**-----------8.��ն���--------------------------------------**\t\n"
		   "\t\t\t**-----------9.��������--------------------------------------**\t\n"
		   "\t\t\t**-----------10.���ٶ���-------------------------------------**\t\n"
		   "\t\t\t**-----------0.�˳�����(ע�������ٶ��У�---------------------**\t\n"
		   "\t\t\t***************************************************************\t\n");
}
//�����ͷԪ�� 
void gethead(AQueue q,int type){ 
	printf("��ͷԪ��Ϊ��"); 
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


