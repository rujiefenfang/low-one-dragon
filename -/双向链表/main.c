#include "duLinkedList.h"

int main()
{
	DuLNode*head=NULL,*tail=NULL;
	int num=0;
	screen();//��Ļ��ʾ  
	while(scanf("%d",&num)&&num!=0)
	{	printf("\n"); 
		if(num==1){
		InitList_DuL(&head); 		//����ͷ�ڵ� 
		InitList_DuL(&tail);		//����β�ڵ� 
		head->next=tail;
		tail->prior=head;			//ͷβ�ڵ����� 
		printf("�����ɹ�\n");
		}	
		if(num==2){
		//��������
		if(head==NULL) printf("����δ����\n");
		else TraverseList_DuL(head,tail);
		}
		if(num==3){
		//���뵽ͷ�ڵ����
			if(head==NULL) printf("����δ����\n");
			else{ 
				DuLNode*node;
				InitList_DuL(&node);  //��������ڵ� 
				printf("����ֵ����");
				scanf("%d",&node->data); 
				InsertAfterList_DuL(head,node);
			} 
		}
		if(num==4){
		//���뵽β�ڵ�ǰ 
			if(head==NULL) printf("����δ����\n");
			else{ 
				DuLNode*node;
				InitList_DuL(&node);  //��������ڵ� 
				printf("����ֵ����"); 
				scanf("%d",&node->data);
				InsertBeforeList_DuL(tail,node);
			}
		}
		
		if(num==5){
		//��������
			 DestroyList_DuL(&head);
			 printf("���������٣��ٴβ��������´�������\n"); 
			  
		}
		if(num==6){
		//ɾ���ڵ�	
		if(head==NULL||head->next==tail) printf("����δ�����������м��޽ڵ�\n");
		 
		else{
			printf("����ɾ���ڵ�λ��(ͷ�ڵ㣬β�ڵ㲻����):"); //����ڵ�λ��
			int i;
			scanf("%d",&i);
			DuLNode *p;
			watch(&p,head,i);  //�ҵ��ڵ� 
			ElemType e;
			DeleteList_DuL(p,&e);	
			}			 
		}
		
		printf("���������ָ��(����0����):\n");
	}	
}

