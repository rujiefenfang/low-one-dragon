#include "LinkStack.h"
int main(){
	LinkStack s;
	int i;
	printf("1����ʼ����ջ\n2���ж��Ƿ�Ϊ��\n3����ȡջ��Ԫ��\n4�����ջ\n");
	printf("5������ջ\n6�����ջ����\n7����ջ\n8����ջ\n0���˳�����\n");
	printf("����ָ�\n");
	while(scanf("%d",&i)&&i!=0){
		if(i==1){ //��ʼ����ջ 
			initLStack(&s);
		}
		if(i==2){ //�ж��Ƿ�Ϊ�� 
			isEmptyLStack(&s);	
		} 
		if(i==3){ //��ȡջ��Ԫ�� 
			int sum;
			getTopLStack(&s,&sum); 
		}
		if(i==4){  //���ջ
			clearLStack(&s);
		} 
		if(i==5){	//����ջ 
			destroyLStack(&s);
		}
		if(i==6){  //���ջ����
			int length;
			LStackLength(&s,&length);	
		}
		if(i==7){ //��ջ 
			int data;
			printf("������ջ��ֵ��");
			scanf("%d",&data); 
			pushLStack(&s,data);
		}
		if(i==8){ //��ջ 
			int num;
			popLStack(&s,&num);
		}
		if(i==0){
			break;
		}
		printf("����������ָ�\n");
	} 	
}
