#include "LinkStack.h"


Status initLStack(LinkStack *s)//初始化栈
{
	s->top=(StackNode*)malloc(sizeof(StackNode));
	if(!s->top) printf("创建失败！"); 
	else{
		s->count=0;
		s->top=NULL;
		printf("创建成功！\n");
	}	
 } 
Status isEmptyLStack(LinkStack *s)//判断栈是否为空
{
	if(s->top==NULL) printf("栈为空\n");
	else printf("栈非空\n"); 
 } 
Status getTopLStack(LinkStack *s,ElemType *e)//得到栈顶元素
{
	if(s->top==NULL) printf("栈顶无节点元素\n");
	else {
		*e=s->top->data;
		printf("栈顶元素为%d\n",s->top->data);	
	}
}
Status clearLStack(LinkStack *s)//清空栈
{
	LinkStackPtr p;
	while(s->top){
		p=s->top;
		s->top=s->top->next;
		s->count--;
		free(p);
	} 
} 
Status destroyLStack(LinkStack *s)//销毁栈
{
	clearLStack(s);
	s=NULL;
} 
Status LStackLength(LinkStack *s,int *length)//检测栈长度
{
	*length=s->count;
	printf("长度为%d",*length);
} 
Status pushLStack(LinkStack *s,ElemType data)//入栈
{
	LinkStackPtr p=(LinkStackPtr)malloc(sizeof(StackNode));//申请结构体节点 
	if(p){
		p->data=data;     //赋值 
		p->next=s->top;   //节点尾连接栈顶 
		s->top=p;		//栈顶指向节点	
		s->count++;      //数据加一 
		printf("入栈成功\n"); 
	}
	else printf("入栈失败"); 
}
Status popLStack(LinkStack *s,ElemType *data)//出栈
{
	if(s->top!=NULL){
		LinkStackPtr p; 
		p=s->top;              //储存栈顶 
		*data=p->data;         //出栈数据     
		s->top=s->top->next;   //栈顶转移到下一个 
		s->count--;			   //容量减一 
		free(p);
		printf("弹出元素为%d\n",*data);          	 //释放储存的栈顶对应节点 
	}else{
		printf("栈顶无元素\n"); 
	}
}

