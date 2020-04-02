#include "duLinkedList.h"

int main()
{
	DuLNode*head=NULL,*tail=NULL;
	int num=0;
	screen();//屏幕显示  
	while(scanf("%d",&num)&&num!=0)
	{	printf("\n"); 
		if(num==1){
		InitList_DuL(&head); 		//创建头节点 
		InitList_DuL(&tail);		//创建尾节点 
		head->next=tail;
		tail->prior=head;			//头尾节点链接 
		printf("创建成功\n");
		}	
		if(num==2){
		//遍历链表
		if(head==NULL) printf("链表未创建\n");
		else TraverseList_DuL(head,tail);
		}
		if(num==3){
		//插入到头节点后面
			if(head==NULL) printf("链表未创建\n");
			else{ 
				DuLNode*node;
				InitList_DuL(&node);  //创建插入节点 
				printf("插入值输入");
				scanf("%d",&node->data); 
				InsertAfterList_DuL(head,node);
			} 
		}
		if(num==4){
		//插入到尾节点前 
			if(head==NULL) printf("链表未创建\n");
			else{ 
				DuLNode*node;
				InitList_DuL(&node);  //创建插入节点 
				printf("插入值输入"); 
				scanf("%d",&node->data);
				InsertBeforeList_DuL(tail,node);
			}
		}
		
		if(num==5){
		//销毁链表
			 DestroyList_DuL(&head);
			 printf("链表已销毁，再次操作请重新创建链表\n"); 
			  
		}
		if(num==6){
		//删除节点	
		if(head==NULL||head->next==tail) printf("链表未创建或链表中间无节点\n");
		 
		else{
			printf("输入删除节点位置(头节点，尾节点不计入):"); //输入节点位置
			int i;
			scanf("%d",&i);
			DuLNode *p;
			watch(&p,head,i);  //找到节点 
			ElemType e;
			DeleteList_DuL(p,&e);	
			}			 
		}
		
		printf("请输入你的指令(输入0结束):\n");
	}	
}

