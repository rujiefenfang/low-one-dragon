#include "LinkStack.h"


Status initLStack(LinkStack *s)//��ʼ��ջ
{
	s->top=(StackNode*)malloc(sizeof(StackNode));
	if(!s->top) printf("����ʧ�ܣ�"); 
	else{
		s->count=0;
		s->top=NULL;
		printf("�����ɹ���\n");
	}	
 } 
Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if(s->top==NULL) printf("ջΪ��\n");
	else printf("ջ�ǿ�\n"); 
 } 
Status getTopLStack(LinkStack *s,ElemType *e)//�õ�ջ��Ԫ��
{
	if(s->top==NULL) printf("ջ���޽ڵ�Ԫ��\n");
	else {
		*e=s->top->data;
		printf("ջ��Ԫ��Ϊ%d\n",s->top->data);	
	}
}
Status clearLStack(LinkStack *s)//���ջ
{
	LinkStackPtr p;
	while(s->top){
		p=s->top;
		s->top=s->top->next;
		s->count--;
		free(p);
	} 
} 
Status destroyLStack(LinkStack *s)//����ջ
{
	clearLStack(s);
	s=NULL;
} 
Status LStackLength(LinkStack *s,int *length)//���ջ����
{
	*length=s->count;
	printf("����Ϊ%d",*length);
} 
Status pushLStack(LinkStack *s,ElemType data)//��ջ
{
	LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));//����ṹ��ڵ� 
	if(p){
		p->data=data;     //��ֵ 
		p->next=s->top;   //�ڵ�β����ջ�� 
		s->top=p;		//ջ��ָ��ڵ�	
		s->count++;      //���ݼ�һ 
		printf("��ջ�ɹ�\n"); 
	}
	else printf("��ջʧ��"); 
}
Status popLStack(LinkStack *s,ElemType *data)//��ջ
{
	if(s->top!=NULL){
		LinkStackPtr p; 
		p=s->top;              //����ջ�� 
		*data=p->data;         //��ջ����     
		s->top=s->top->next;   //ջ��ת�Ƶ���һ�� 
		s->count--;			   //������һ 
		free(p);
		printf("����Ԫ��Ϊ%d\n",*data);          	 //�ͷŴ����ջ����Ӧ�ڵ� 
	}else{
		printf("ջ����Ԫ��\n"); 
	}
}

