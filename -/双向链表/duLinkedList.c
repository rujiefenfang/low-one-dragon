#include "duLinkedList.h"

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L){
	*L=(DuLinkedList)malloc(sizeof(DuLNode));
	(*L)->next=NULL;
	(*L)->prior=NULL;	
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L){
	DuLinkedList p;
	while(NULL!=*L)
	{
		p=*L;			//储存*L的节点 
		*L=p->next;
		free(p);		//释放节点 
	}
	*L=NULL;			 
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q){
	//链接p,q 
	DuLNode *p1;
	p1=p->prior;
	p->prior=q;
	q->prior=p1;
	p1->next=q;
	q->next=p;
} 

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q){
	DuLNode* p1;
	p1=p->next;			
	p->next=q;			 
	q->next=p1;
	p1->prior=q;
	q->prior=p;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e){
	DuLNode *p1,*p2;
	p1=p->prior;   //保存前一个节点地址
	p2=p->next;    //保存后一个节点地址
	p1->next=p2;
	p2->prior=p1;  //连接前后节点 
	printf("节点值e=%d\n",p->data);
	*e=p->data; 
	free(p); 
	p=NULL; 
} 
//找到要删除节点位置 
void watch(DuLinkedList *node,DuLNode*head,int n){
	for(;n>0;n--){	
		*node=head->next;
		head=head->next;
		//节点不存在时 
		if(head->next==NULL){
			printf("节点不存在\n");
			break; 
		}
		} 
	}


/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */ 
//void *visit(ElemType e);
//void TraverseList_DuL(DuLinkedList L);
void TraverseList_DuL(DuLNode *head,DuLNode *tail){
	if(head->next==tail)
		printf("头尾节点中间无节点\n");
	else{
		while(head->next!=tail){
		printf("->%d",head->next->data);
		head=head->next;
		}			
	}
}




//显示操作
void screen(){
	printf("1、创建双向链表\n2、遍历链表\n3、在表头后插入节点\n4、在表尾前插入节点\n5、销毁链表\n6、删除节点\n");
	printf("请输入你的指令(输入0结束):\n");
	 
} 





