#include "Link.h"

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {		
	*L=(LNode*)malloc(sizeof(LNode)); //���������ݵı�ͷ 
    LinkedList p1;  
    LinkedList p2;
    int n=5;
    p2=p1=(LNode*)malloc(sizeof(LNode));
    (*L)->next=p1;
    p1->data=1; 
	int i;
    for( i=2;i<=n;i++)
    {	
    	p1=(LNode*)malloc(sizeof(LNode));
    	p2->next=p1;
    	p2=p1;
    	p1->data=i;
	}
	p1->next=NULL; 
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p;
	while(NULL!=*L)
	{
		p=*L;
		*L=p->next;
		free(p);
		
	}
	*L=NULL;
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	LNode *p1;  //��ʱ�ڵ�
	p1=p->next; //������һ���ڵ� 
	p->next=q;  //���ӽڵ� 
	q->next=p1;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	if(p!=NULL){
	LNode *temp,*node;
	temp=p->next;       //��ȡp��ĵ�һ���ڵ� 
	node=temp->next;    //����p��ڶ����ڵ�ĵ�ַ
	*e=temp->data;      //��ֵ 
	p->next=node;       //����p�͵ڶ����ڵ� 
	free(temp);         //�ͷ�p���һ���ڵ� 
	printf("e=%d",*e); 
}
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */

void TraverseList(LinkedList L) {
	if(L==NULL)
		printf("����һ��������");
	else
	{ 
	LNode *p;
	p=L->next;
	printf("���������:head"); 
	while(p)
	{
		visit(p->data);
		p=p->next;
	 } 
	} 
} 
void visit(ElemType e)
{
	printf("->%d ",e);
} 


/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
//δд 
Status SearchList(LinkedList L, ElemType e) {
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	if(*L!=NULL)
	{
		LNode *p;			//����ÿ�η�ת��ĵ�һ���ڵ� 
		LNode *p1;			//ÿ�ζ�ָ��ǰһ���ڵ�	
		LNode *p2;			// ����δ��תǰ����һ���ڵ� 
		p1=(*L)->next;
		p2=p1->next;
		p1->next=NULL;
		p=p1;
		while (p2!= NULL) {
			p1=p2;
			p2=p1->next;
			p1->next=p;
			p=p1;
		}
		
		(*L)->next=p;
		printf("������ɹ���\n");		 
	}
	else printf("����һ��������\n");
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LNode *p1,*p2;
	p1=L;
	p2=L->next->next;
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1==p2){
			printf("����һ��ѭ������");
			break;
		}
		p1=p1->next;
		p2=p2->next->next;
		if(p1==NULL||p2==NULL)
			printf("�ⲻ��һ��ѭ������"); 
	 }
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
//д��֮����bug 
LNode* ReverseEvenList(LinkedList *L) {

}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList L) {
	LNode*fast,*slow;     //��������ڵ� 
    fast=slow=L;
	int n=0;
	while(fast!=NULL&&fast->next!=NULL)
	{
		fast=fast->next->next;   //��ڵ��ƶ����� 
		slow=slow->next;		// ���ڵ��ƶ�һ�� 
		n++;
	}
	if(n%2!=0)					//�������ڵ�ʱ 
		printf("�м�ڵ��ǵ�%d��������ֵ��%d\n",n,slow->data);
	else		
	{							//ż�����ڵ�ʱ 
		printf("�м�ڵ�Ϊ��%d,%d����ֵ�ֱ�Ϊ%d,%d\n",n,n+1,slow->data,slow->next->data);
	}
}
//���ҷ�������L�е�n���ڵ� 
LNode  *watch(LinkedList L,int n){
	if(L!=NULL){
	LNode *p1=L->next,*p2;   //p1ָ���һ���ڵ� 
	int i=0;              //���ҽڵ�ĸ�����������ͷ�ڵ� 
	while(p1!=NULL){
		p1=p1->next;
		i++;
	} 	 
	if(n>i){
	printf("�ڵ㲻����");
	return 0;
	}
	else{
		int j=0;
		
		for(;j<=n;j++){
			p1=L;//p1����ָ���һ���ڵ�
			L=L->next; 		
		}return p1; 
	} 
    }
    else
		return 0;
}
//��ʾ���� 
void screen(LNode *head){
	printf("****************\n");
	printf("*1.��������    *\n*2.����ڵ�    *\n*3.ɾ���ڵ�    *\n*4.��ת����    *\n*5.�����Ƿ�ɻ�*\n");
	printf("*6.�м�ڵ�    *\n*7.��ż�ڵ����*\n*8.�ͷ�����    *\n");
	printf("****************\n");
	printf("\n");
//	printf("�ѽ�������");
//	TraverseList(head); 
	printf("\n");
	printf("������Ĳ���ָ��,����0������");
	printf("\n");
}

