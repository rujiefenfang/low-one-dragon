#include "Link.h"
int main()
{
 	LNode *head;
	InitList(&head);
    ElemType e;
	int i;
	//��ʾ����ָ�� 
	screen(head);  

	while(scanf("%d",&i)&&i!=0){
	
	printf("\n"); 
	if(i==1){
		//�������� 
		TraverseList(head);
		}
	 
	if(i==2){
		//����ڵ� 
		int num;
		LNode *Node,*node;
		Node=(LNode*)malloc(sizeof(LNode));//���������Ľڵ��ڴ� 
		printf("����Ҫ�������ݣ�");
		scanf("%d",&Node->data);
		printf("��Ҫ�������ĸ��ڵ�֮��(head��0�ڵ�)��");
		scanf("%d",&num);
		node=watch(head,num);           //�ҵ��ڵ�
		if(node!=NULL) 
		InsertList(node,Node);			//���ӽڵ� 
		}
	if(i==3){
		//ɾ���ڵ� 
		LNode *p1;
		int sum;
		printf("��Ҫɾ���ڼ����ڵ�(head�ǵ�0�ڵ�)��");
		scanf("%d",&sum);
		p1=watch(head,(sum-1));
		DeleteList(p1, &e);
	}
	if(i==4){
		//����ת
		if(head->next==NULL) printf("ֻ��ͷ�ڵ�"); 
		else ReverseList(&head);
	}
	if(i==5){
		//�ж������Ƿ�ɻ�
		if(head->next!=NULL) IsLoopList(head);
		else printf("ֻ��ͷ�ڵ�"); 
	} 
	if(i==6){
		//�ҵ��м�ڵ� 
		FindMidNode(head);
	}
	if(i==7){
		//��ż�㻥��	
		 ReverseEvenList(&head);
	}
	if(i==8){
		//�ͷ����� 
		DestroyList(&head);
		printf("�����Ѿ�����");
	} 
	if(i==9){
		InitList(&head);
		printf("��������ɹ�"); 
	}	
		 
	printf("\n����������ָ�����0������\n");
}
}


