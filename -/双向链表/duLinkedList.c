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
		p=*L;			//����*L�Ľڵ� 
		*L=p->next;
		free(p);		//�ͷŽڵ� 
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
	//����p,q 
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
	p1=p->prior;   //����ǰһ���ڵ��ַ
	p2=p->next;    //�����һ���ڵ��ַ
	p1->next=p2;
	p2->prior=p1;  //����ǰ��ڵ� 
	printf("�ڵ�ֵe=%d\n",p->data);
	*e=p->data; 
	free(p); 
	p=NULL; 
} 
//�ҵ�Ҫɾ���ڵ�λ�� 
void watch(DuLinkedList *node,DuLNode*head,int n){
	for(;n>0;n--){	
		*node=head->next;
		head=head->next;
		//�ڵ㲻����ʱ 
		if(head->next==NULL){
			printf("�ڵ㲻����\n");
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
		printf("ͷβ�ڵ��м��޽ڵ�\n");
	else{
		while(head->next!=tail){
		printf("->%d",head->next->data);
		head=head->next;
		}			
	}
}




//��ʾ����
void screen(){
	printf("1������˫������\n2����������\n3���ڱ�ͷ�����ڵ�\n4���ڱ�βǰ����ڵ�\n5����������\n6��ɾ���ڵ�\n");
	printf("���������ָ��(����0����):\n");
	 
} 





