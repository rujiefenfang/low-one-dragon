#include "Link.h"

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {		
	*L=(LNode*)malloc(sizeof(LNode)); //创建无数据的表头 
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
	LNode *p1;  //临时节点
	p1=p->next; //储存下一个节点 
	p->next=q;  //链接节点 
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
	temp=p->next;       //提取p后的第一个节点 
	node=temp->next;    //保留p后第二个节点的地址
	*e=temp->data;      //赋值 
	p->next=node;       //链接p和第二个节点 
	free(temp);         //释放p后第一个节点 
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
		printf("这是一个空链表");
	else
	{ 
	LNode *p;
	p=L->next;
	printf("这个链表是:head"); 
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
//未写 
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
		LNode *p;			//储存每次反转后的第一个节点 
		LNode *p1;			//每次都指向前一个节点	
		LNode *p2;			// 储存未反转前的下一个节点 
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
		printf("链表倒序成功！\n");		 
	}
	else printf("这是一个空链表！\n");
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
			printf("这是一个循环链表！");
			break;
		}
		p1=p1->next;
		p2=p2->next->next;
		if(p1==NULL||p2==NULL)
			printf("这不是一个循环链表！"); 
	 }
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
//写完之后有bug 
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
	LNode*fast,*slow;     //定义快慢节点 
    fast=slow=L;
	int n=0;
	while(fast!=NULL&&fast->next!=NULL)
	{
		fast=fast->next->next;   //快节点移动两步 
		slow=slow->next;		// 慢节点移动一步 
		n++;
	}
	if(n%2!=0)					//奇数个节点时 
		printf("中间节点是第%d个，它的值是%d\n",n,slow->data);
	else		
	{							//偶数个节点时 
		printf("中间节点为第%d,%d个，值分别为%d,%d\n",n,n+1,slow->data,slow->next->data);
	}
}
//查找返回链表L中第n个节点 
LNode  *watch(LinkedList L,int n){
	if(L!=NULL){
	LNode *p1=L->next,*p2;   //p1指向第一个节点 
	int i=0;              //查找节点的个数，不包括头节点 
	while(p1!=NULL){
		p1=p1->next;
		i++;
	} 	 
	if(n>i){
	printf("节点不存在");
	return 0;
	}
	else{
		int j=0;
		
		for(;j<=n;j++){
			p1=L;//p1重新指向第一个节点
			L=L->next; 		
		}return p1; 
	} 
    }
    else
		return 0;
}
//显示操作 
void screen(LNode *head){
	printf("****************\n");
	printf("*1.遍历链表    *\n*2.插入节点    *\n*3.删除节点    *\n*4.反转链表    *\n*5.链表是否成环*\n");
	printf("*6.中间节点    *\n*7.奇偶节点调换*\n*8.释放链表    *\n");
	printf("****************\n");
	printf("\n");
//	printf("已建立链表：");
//	TraverseList(head); 
	printf("\n");
	printf("输入你的操作指令,输入0结束：");
	printf("\n");
}

