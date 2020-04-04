#include "Sqstack.h"
//基于数组的顺序栈

Status initStack(SqStack *s,int sizes)//初始化栈
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
Status isEmptyStack(SqStack *s)//判断栈是否为空
{
	if(s->size!=-1){
		if(s->top==0)printf("栈为空\n");
		else printf("栈非空\n");
	}
	else printf("栈未初始化\n"); 
	
		
 } 
Status getTopStack(SqStack *s,ElemType *e) //得到栈顶元素
{	
	if(s->size!=-1){
		if(s->top>0){
		*e=s->elem[s->top-1];
		printf("栈顶元素为%d\n",*e);
		}else printf("栈顶无插入元素\n"); 
	}
	else printf("栈未初始化\n");
 } 
Status clearStack(SqStack *s)//清空栈
{	
	if(s->size!=-1){
		while(s->top!=0){
			s->top--;
		}
		printf("清空完成\n");
	}
	else printf("栈未初始化\n");	 
} 
Status destroyStack(SqStack *s)//销毁栈
{
	if(s->size!=-1){
		free(s->elem);
		s->size=-1;
		s->top=0;
		s=NULL;
		printf("栈已销毁\n"); 
	}
	else printf("栈未初始化,或已经销毁\n");	 
 } 
Status stackLength(SqStack *s,int *length)//检测栈长度
{ 	
	if(s!=NULL){
		*length=s->top;
		printf("有数据长度：%d\n",s->top);
		printf("剩余长度：%d\n",s->size-s->top);
	}
	else printf("栈未初始化\n");	 
 } 
Status pushStack(SqStack *s,ElemType data)//入栈
{	
	if(s->size!=-1){
	if(s->top==s->size){
		printf("满栈\n");
		return 0;
	}
	s->elem[s->top]=data;
	s->top++;
	return 1;
	}
	else printf("栈未初始化\n");
 } 
Status popStack(SqStack *s,ElemType *data)//出栈
{	
	if(s->size!=-1){ 
		if(s->top<=0){
			printf("空栈\n");
			return 0; 
		}
		s->top--;
		*data=s->elem[s->top];
		printf("%d",*data); 
		return 1;
	}
	else printf("栈未初始化\n"); 
 } 
 //交互界面显示
 void screen(){
	printf("     1:初始化栈\n     2:入栈\n     3:出栈\n     4:检查是否为空栈\n     5:输出栈的长度和剩余长度\n     6:栈顶元素\n ");
	printf("    7:清空元素\n     8:销毁栈\n     0:结束\n");	
}
