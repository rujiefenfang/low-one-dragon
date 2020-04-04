#include "Sqstack.h"
//���������˳��ջ

Status initStack(SqStack *s,int sizes)//��ʼ��ջ
{	 
	s->elem=(ElemType*)malloc(sizeof(ElemType)*sizes);
	if(s==NULL||s->elem==NULL){
		free(s);
		free(s->elem);
	}
	else{
		s->size=sizes;
		s->top=0;
	} 
 } 
Status isEmptyStack(SqStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if(s->size!=-1){
		if(s->top==0)printf("ջΪ��\n");
		else printf("ջ�ǿ�\n");
	}
	else printf("ջδ��ʼ��\n"); 
	
		
 } 
Status getTopStack(SqStack *s,ElemType *e) //�õ�ջ��Ԫ��
{	
	if(s->size!=-1){
		if(s->top>0){
		*e=s->elem[s->top-1];
		printf("ջ��Ԫ��Ϊ%d\n",*e);
		}else printf("ջ���޲���Ԫ��\n"); 
	}
	else printf("ջδ��ʼ��\n");
 } 
Status clearStack(SqStack *s)//���ջ
{	
	if(s->size!=-1){
		while(s->top!=0){
			s->top--;
		}
		printf("������\n");
	}
	else printf("ջδ��ʼ��\n");	 
} 
Status destroyStack(SqStack *s)//����ջ
{
	if(s->size!=-1){
		free(s->elem);
		s->size=-1;
		s->top=0;
		s=NULL;
		printf("ջ������\n"); 
	}
	else printf("ջδ��ʼ��,���Ѿ�����\n");	 
 } 
Status stackLength(SqStack *s,int *length)//���ջ����
{ 	
	if(s!=NULL){
		*length=s->top;
		printf("�����ݳ��ȣ�%d\n",s->top);
		printf("ʣ�೤�ȣ�%d\n",s->size-s->top);
	}
	else printf("ջδ��ʼ��\n");	 
 } 
Status pushStack(SqStack *s,ElemType data)//��ջ
{	
	if(s->size!=-1){
	if(s->top==s->size){
		printf("��ջ\n");
		return 0;
	}
	s->elem[s->top]=data;
	s->top++;
	return 1;
	}
	else printf("ջδ��ʼ��\n");
 } 
Status popStack(SqStack *s,ElemType *data)//��ջ
{	
	if(s->size!=-1){ 
		if(s->top<=0){
			printf("��ջ\n");
			return 0; 
		}
		s->top--;
		*data=s->elem[s->top];
		printf("%d",*data); 
		return 1;
	}
	else printf("ջδ��ʼ��\n"); 
 } 
 //����������ʾ
 void screen(){
	printf("     1:��ʼ��ջ\n     2:��ջ\n     3:��ջ\n     4:����Ƿ�Ϊ��ջ\n     5:���ջ�ĳ��Ⱥ�ʣ�೤��\n     6:ջ��Ԫ��\n ");
	printf("    7:���Ԫ��\n     8:����ջ\n     0:����\n");	
}
