#include "LinkStack.h"
int main(){
	LinkStack s;
	int i;
	printf("1、初始化链栈\n2、判断是否为空\n3、获取栈顶元素\n4、清空栈\n");
	printf("5、销毁栈\n6、检测栈长度\n7、入栈\n8、出栈\n0、退出程序\n");
	printf("输入指令：\n");
	while(scanf("%d",&i)&&i!=0){
		if(i==1){ //初始化链栈 
			initLStack(&s);
		}
		if(i==2){ //判断是否为空 
			isEmptyLStack(&s);	
		} 
		if(i==3){ //获取栈顶元素 
			int sum;
			getTopLStack(&s,&sum); 
		}
		if(i==4){  //清空栈
			clearLStack(&s);
		} 
		if(i==5){	//销毁栈 
			destroyLStack(&s);
		}
		if(i==6){  //检测栈长度
			int length;
			LStackLength(&s,&length);	
		}
		if(i==7){ //入栈 
			int data;
			printf("输入入栈的值：");
			scanf("%d",&data); 
			pushLStack(&s,data);
		}
		if(i==8){ //出栈 
			int num;
			popLStack(&s,&num);
		}
		if(i==0){
			break;
		}
		printf("请重新输入指令：\n");
	} 	
}
