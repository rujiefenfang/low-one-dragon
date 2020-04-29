#include"LinkTree.h"
//初始化 
Status InitBiTree(BiTree *T){
	*T=NULL;
}
//销毁 
Status DestroyBiTree(BiTree T)
{
	if (T==NULL)  return 1;
	DestroyBiTree(T->lchild);
	DestroyBiTree(T->rchild);
	free(T);
	return;
}
//创建二叉树 
Status CreateBiTree(BiTree *T, char* definition)
{
	int j=0,flag=0,top=-1;//flag：1代表左孩子，2代表右孩子 
	BiTNode *p=NULL,*stack[100]={0};
	while(definition[j]!='\0'){
		switch(definition[j]){
			case '(':
				flag=1;
				top++;
				stack[top]=p;
				break;
			case',':
				flag=2;
				break;
			case')':
				top--;
				break;
			default:
				p=(BiTNode*)malloc(sizeof(BiTNode));
				p->data=definition[j];
				p->lchild=p->rchild=NULL;
				if((*T)==NULL) (*T)=p;
				else{
					switch(flag){
						case 1:
							stack[top]->lchild=p;
							break;
						case 2:
							stack[top]->rchild=p;
							break; 
					}
				}
				break;
		}
		j++;
		
	} 

} 
//前序遍历 
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	if(T==NULL) return 0;
	visit(T->data);
	PreOrderTraverse(T->lchild,visit);
	PreOrderTraverse(T->rchild,visit); 
} 
//中序遍历
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	if(T==NULL) return 0;
	InOrderTraverse(T->lchild,visit);
	visit(T->data);
	InOrderTraverse(T->rchild,visit);
 } 
//后续遍历
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	if (T==NULL) return 0;
	PostOrderTraverse(T->lchild,visit);
	PostOrderTraverse(T->rchild,visit);
	visit(T->data); 
 } 
 //层序遍历 //利用队列 
 Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	BiTree Tqueue[50];
	BiTree p=NULL;
	int front,rear;
	front=rear=0;
	if(T!=NULL){
		rear=(rear+1)%50;
		Tqueue[rear]=T;
		while(rear!=front){
			//printf("(%d %d)",rear,front);
			front=(front+1)%50;
			p=Tqueue[front];
			//if(rear==front) break;
			visit(p->data);
			if(p->lchild){
				rear=(rear+1)%50;
				Tqueue[rear]=p->lchild;
			}
			if(p->rchild){
				rear=(rear+1)%50;
				Tqueue[rear]=p->rchild;
			}
		}
	} 	
} 
Status visit(char a){
	printf("%c ",a);
} 
//非递归先序遍历
Status preorderTraverse_1(BiTree T){
	BiTree arr[50]; //创建节点 
	BiTree p=NULL;
	int i=0;
	if(T!=NULL){
		arr[i]=T;
		i++;
		while(i!=0){
			p=arr[i-1];  	
			while(p){  //先访问根节点，左孩子存在时入栈，根节点指向左孩子 
				printf("%c ",p->data);
				arr[i]=p->lchild;
				i++;
				p=arr[i-1];
			}
			p=arr[i-1];
			i--;
			if(i!=0){
				p=arr[i-1];
				i--;
				arr[i]=p->rchild; //左孩子都访问完后转向右孩子 
				i++;   //左节点遍历完，返回 
			}
			
		}
	}
} 
//中序遍历非递归
Status InOrderTraverse_1(BiTree T){
	BiTree arr[50];
	BiTree p=NULL;
	int i=0;
	if(T!=NULL){
		arr[i]=T;//根节点入栈 
		i++;
		while(i!=0){
			p=arr[i-1];
			
			while(p){
				arr[i]=p->lchild;
				i++;
				p=arr[i-1];
			} //入栈左孩子 
			p=arr[i-1];
			i--;
			if(i!=0){
				p=arr[i-1];
				i--;
				printf("%c ",p->data);
				arr[i]=p->rchild;
				i++;
			}
			
		}
	}
}  
//后序遍历
Status PostOrderTraverse_1(BiTree T){
	BiTree arr[50];
	BiTree pre=NULL,p=T;
	int i=0;
	if(T!=NULL||i!=0){
		while(p!=NULL||i!=0){
			while(p)
			{
				arr[i]=p;
				i++;
				p=p->lchild;
			}
			if(i!=0){
				p=arr[i-1];			
				if(p->rchild!=NULL&&p->rchild!=pre){ // 未被访问或不存在 
					arr[i]=p;
					p=p->rchild;
				}
				else{
					printf("%c ",p->data);
					i--;    //输出后返回上一个节点 
					pre=p;  //记录被访问过的节点 
					p=NULL;  
				}
			}
		}
		return 1;
	}
}
//前缀表达式构建二叉树 
void creat(BiTree*t,char *a,int *i){
	int j=*i;
	if(a[j]=='\0') return;
	*t=(BiTree)malloc(sizeof(BiTNode));
	(*t)->data=a[j];
	(*t)->lchild=NULL;
	(*t)->rchild=NULL;
	      ++*i;
	if(a[j]<'0'||a[j]>'9'){
		creat(&((*t)->lchild),a,i);
		creat(&((*t)->rchild),a,i);
	}
}  
//前缀表达式计算值 
float Value(BiTree T){
	if(T==NULL) return 0;
	if(T->data<='9'&&T->data>='0') return (T->data-'0');
	else{
		switch(T->data){
			case'+':
				return Value(T->lchild)+Value(T->rchild);
			case'-':
				return Value(T->lchild)-Value(T->rchild);
			case'*':
				return Value(T->lchild)*Value(T->rchild);
			case'/':
				return Value(T->lchild)/Value(T->rchild);
		}
	} 
	
} 
