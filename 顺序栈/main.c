#include "Sqstack.h"
int main()
{
	int i,sizes;
	SqStack s;
	s.elem=NULL;
	s.size=-1;
	s.top=0;     //初始化定义的结构体变量 
	screen();
	printf("输入指令：\n"); 
	while(scanf("%d",&i)&&i!=0){
		if(i==1){ //创建栈 
			printf("输入你要的栈的容量：");
			scanf("%d",&sizes);
			initStack(&s,sizes);
		}
		if(i==2){ //入栈 
			int num;
			printf("输入你要入栈的值："); 
			scanf("%d",&num);
			pushStack(&s,num);
		}
		if(i==3){ //出栈 
			int data;
			popStack(&s,&data); 
		}
		if(i==4){ //检验栈是否为空 
			isEmptyStack(&s); 
		}
		if(i==5){ //输出栈的长度和剩余长度 
			int length;
			stackLength(&s,&length);
		}
		if(i==6){ //栈顶元素 
			int a;
			getTopStack(&s,&a); 
		}
		if(i==7){	//清空元素 
			clearStack(&s);
		} 
		if(i==8){	//销毁栈 
			destroyStack(&s);
		}
		if(i==0){
			destroyStack(&s);
			printf("栈已销毁，退出成功\n");
			break; 
		}
		printf("请重新输入指令：\n");

	}

}
