#include"LinkTree.h"
//��ʼ�� 
Status InitBiTree(BiTree *T){
	*T=NULL;
}
//���� 
Status DestroyBiTree(BiTree T)
{
	if (T==NULL)  return 1;
	DestroyBiTree(T->lchild);
	DestroyBiTree(T->rchild);
	free(T);
	return;
}
//���������� 
Status CreateBiTree(BiTree *T, char* definition)
{
	int j=0,flag=0,top=-1;//flag��1�������ӣ�2�����Һ��� 
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
//ǰ����� 
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	if(T==NULL) return 0;
	visit(T->data);
	PreOrderTraverse(T->lchild,visit);
	PreOrderTraverse(T->rchild,visit); 
} 
//�������
Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	if(T==NULL) return 0;
	InOrderTraverse(T->lchild,visit);
	visit(T->data);
	InOrderTraverse(T->rchild,visit);
 } 
//��������
Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
	if (T==NULL) return 0;
	PostOrderTraverse(T->lchild,visit);
	PostOrderTraverse(T->rchild,visit);
	visit(T->data); 
 } 
 //������� //���ö��� 
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
//�ǵݹ��������
Status preorderTraverse_1(BiTree T){
	BiTree arr[50]; //�����ڵ� 
	BiTree p=NULL;
	int i=0;
	if(T!=NULL){
		arr[i]=T;
		i++;
		while(i!=0){
			p=arr[i-1];  	
			while(p){  //�ȷ��ʸ��ڵ㣬���Ӵ���ʱ��ջ�����ڵ�ָ������ 
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
				arr[i]=p->rchild; //���Ӷ��������ת���Һ��� 
				i++;   //��ڵ�����꣬���� 
			}
			
		}
	}
} 
//��������ǵݹ�
Status InOrderTraverse_1(BiTree T){
	BiTree arr[50];
	BiTree p=NULL;
	int i=0;
	if(T!=NULL){
		arr[i]=T;//���ڵ���ջ 
		i++;
		while(i!=0){
			p=arr[i-1];
			
			while(p){
				arr[i]=p->lchild;
				i++;
				p=arr[i-1];
			} //��ջ���� 
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
//�������
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
				if(p->rchild!=NULL&&p->rchild!=pre){ // δ�����ʻ򲻴��� 
					arr[i]=p;
					p=p->rchild;
				}
				else{
					printf("%c ",p->data);
					i--;    //����󷵻���һ���ڵ� 
					pre=p;  //��¼�����ʹ��Ľڵ� 
					p=NULL;  
				}
			}
		}
		return 1;
	}
}
//ǰ׺���ʽ���������� 
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
//ǰ׺���ʽ����ֵ 
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
