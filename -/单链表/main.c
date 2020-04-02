#include "Link.h"
int main()
{
 	LNode *head;
	InitList(&head);
    ElemType e;
	int i;
	//显示操作指令 
	screen(head);  

	while(scanf("%d",&i)&&i!=0){
	
	printf("\n"); 
	if(i==1){
		//遍历链表 
		TraverseList(head);
		}
	 
	if(i==2){
		//插入节点 
		int num;
		LNode *Node,*node;
		Node=(LNode*)malloc(sizeof(LNode));//分配给插入的节点内存 
		printf("输入要插入数据：");
		scanf("%d",&Node->data);
		printf("你要输入在哪个节点之后(head是0节点)：");
		scanf("%d",&num);
		node=watch(head,num);           //找到节点
		if(node!=NULL) 
		InsertList(node,Node);			//连接节点 
		}
	if(i==3){
		//删除节点 
		LNode *p1;
		int sum;
		printf("你要删除第几个节点(head是第0节点)：");
		scanf("%d",&sum);
		p1=watch(head,(sum-1));
		DeleteList(p1, &e);
	}
	if(i==4){
		//链表反转
		if(head->next==NULL) printf("只有头节点"); 
		else ReverseList(&head);
	}
	if(i==5){
		//判断链表是否成环
		if(head->next!=NULL) IsLoopList(head);
		else printf("只有头节点"); 
	} 
	if(i==6){
		//找到中间节点 
		FindMidNode(head);
	}
	if(i==7){
		//奇偶点互换	
		 ReverseEvenList(&head);
	}
	if(i==8){
		//释放链表 
		DestroyList(&head);
		printf("链表已经销毁");
	} 
	if(i==9){
		InitList(&head);
		printf("建立链表成功"); 
	}	
		 
	printf("\n请重新输入指令，输入0结束：\n");
}
}


