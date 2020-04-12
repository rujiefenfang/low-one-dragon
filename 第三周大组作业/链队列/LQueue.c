#include"LQueue.h"
//��ʼ�� 
void InitLQueue(LQueue *Q){
	Node *p=(Node*)malloc(sizeof(Node));//���ﶨ��ͷ�ڵ������� 
	p->next=NULL;
	Q->front=Q->rear=p;
	Q->length=0;
	if(p!=NULL) printf("��ʼ���ɹ�\n");
	else printf("��ʼ��ʧ��\n");
}

//���ٶ���
void DestoryLQueue(LQueue *Q)
{	
	if(Q->length==0) return; 
	ClearLQueue(Q);
	free(Q->front);         
	Q->front=NULL;
 }
 
//�п� 
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->front->next==NULL) return 1;
	else return 0;
}
//�õ�ͷ����Ԫ��
Status GetHeadLQueue(LQueue *Q, void *e){
	memcpy(e,Q->front->next->data,size(Q->front->next->type)); //��ͷԪ�ظ���e 
} 
//�����еĳ���
int LengthLQueue(LQueue *Q){
	return Q->length;
} 
//��� typeΪ�������ͣ����ִ��� 1-���ͣ�2-�ַ��� ��3-������ ��4-�ַ��� 
Status EnLQueue(LQueue *Q, void *data,int type){
	Node *p=(Node*)malloc(sizeof(Node));
	p->data=(void*)malloc(size(type));       
	memcpy(p->data,data,size(type));
	Q->rear->next=p;                  //�´����ڵ����β���� 
	Q->rear=p;                       //��λָ���´����Ľڵ� 
	Q->rear->type=type;
	p->next=NULL;
	Q->length++;	//���ȼ�һ 
}
//����
Status DeLQueue(LQueue *Q){
	Node *p;
	p=Q->front->next;
	Q->front->next=p->next;
	free(p->data);      
	free(p);
	Q->length--;
	if(Q->length==0)
	{
		Q->rear=Q->front;
	 } 
}
//��������� 
void ClearLQueue(LQueue *Q){
	Node *p1,*p2;
	p1=Q->front->next;
	while(Q->front->next!=NULL){
		Q->front->next=p1->next;
		free(p1->data);          //������� 
		free(p1);         //��սڵ� 
		p1=Q->front->next; 
	}
	Q->rear=Q->front;  //ͷβ��� 
	Q->length=0; //������0 
}
//��������
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,int type))
{
	Node *p;
	p=Q->front->next;
	while(p!=NULL){
		foo(p->data,p->type); //���Ԫ�� 
		p=p->next;
	}
	printf("\n"); 
} 
//��ӡtypeΪ�������ͣ����ִ��� 1-���ͣ�2-�ַ��� ��3-������ ��4-�ַ���
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
//type��Ӧ���������ֽ�����typeΪ�������ͣ����ִ��� 1-���ͣ�2-�ַ��� ��3-������ ��4-�ַ��� 
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
//���뺯��
void push(LQueue *Q){
	printf("��������Ҫ������������ͣ�\n");
	printf("1.���� 2.�ַ��� 3.������ 4.�ַ���(��󳤶Ȳ�����20)\n");
	int i;
	scanf("%d",&i);
	printf("������������ݣ�"); 
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
//����ͷ����Ԫ�� 
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
//��Ļ��ʾ
void screen()
{
	printf("\t\t\t***************************************************************\t\n"
	       "\t\t\t**-----------1.��ʼ������------------------------------------**\t\n"
	       "\t\t\t**-----------2.���ٶ���--------------------------------------**\t\n"
		   "\t\t\t**-----------3.�����п�--------------------------------------**\t\n"
		   "\t\t\t**-----------4.���ͷ����Ԫ��--------------------------------**\t\n"
		   "\t\t\t**-----------5.���г���--------------------------------------**\t\n"
		   "\t\t\t**-----------6.���------------------------------------------**\t\n"
		   "\t\t\t**-----------7.����------------------------------------------**\t\n"
		   "\t\t\t**-----------8.��ն���--------------------------------------**\t\n"
		   "\t\t\t**-----------9.��������--------------------------------------**\t\n"
		   "\t\t\t**-----------0.�˳�����(ע�������ٶ��У�---------------------**\t\n"
		   "\t\t\t***************************************************************\t\n");
 } 

