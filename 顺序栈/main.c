#include "Sqstack.h"
int main()
{
	int i,sizes;
	SqStack s;
	s.elem=NULL;
	s.size=-1;
	s.top=0;     //��ʼ������Ľṹ����� 
	screen();
	printf("����ָ�\n"); 
	while(scanf("%d",&i)&&i!=0){
		if(i==1){ //����ջ 
			printf("������Ҫ��ջ��������");
			scanf("%d",&sizes);
			initStack(&s,sizes);
		}
		if(i==2){ //��ջ 
			int num;
			printf("������Ҫ��ջ��ֵ��"); 
			scanf("%d",&num);
			pushStack(&s,num);
		}
		if(i==3){ //��ջ 
			int data;
			popStack(&s,&data); 
		}
		if(i==4){ //����ջ�Ƿ�Ϊ�� 
			isEmptyStack(&s); 
		}
		if(i==5){ //���ջ�ĳ��Ⱥ�ʣ�೤�� 
			int length;
			stackLength(&s,&length);
		}
		if(i==6){ //ջ��Ԫ�� 
			int a;
			getTopStack(&s,&a); 
		}
		if(i==7){	//���Ԫ�� 
			clearStack(&s);
		} 
		if(i==8){	//����ջ 
			destroyStack(&s);
		}
		if(i==0){
			destroyStack(&s);
			printf("ջ�����٣��˳��ɹ�\n");
			break; 
		}
		printf("����������ָ�\n");

	}

}
