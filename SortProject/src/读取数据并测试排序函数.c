#include "../inc/qgsort.h"
//��������
void insertSort(int *a,int n){
	int i=1;
	int temp=0;
	for(i;i<n;i++){
	int j=i-1;
	temp=a[i];
	while(j>=0&&temp<a[j]){
		a[j+1]=a[j];
		j--;
		//if(j==0) break;
	}
	a[j+1]=temp;
}
} 
//�鲢���򣨺ϲ����飩
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{	
	
	int i=begin;
	int j=mid+1;
	int k=0;
//	temp=(int*)malloc(sizeof(int)*(end-begin-1));
//	if(temp==NULL){
//		printf("�ڴ����벻�ɹ�");
//		return;
//	}  
	while(i<=mid&&j<=end)
		temp[k++] = a[i]<a[j]?a[i++]:a[j++];
	while(i<=mid)
		temp[k++] = a[i++];
	while(j<=end)
		temp[k++] = a[j++];
	for(i=0;i<k;i++)
		a[begin+i]=temp[i];
//	free(temp);
}

void MergeSort(int *a,int begin,int end,int *temp)
{
	if(begin>=end) return;
	int mid = (begin+end)/2;
	MergeSort(a,begin,mid,temp);
	MergeSort(a,mid+1,end,temp);
	MergeArray(a,begin,mid,end,temp);	
}
//����
void QuickSort_Recursion(int *a, int begin, int end)
{
	if(begin<end){
		int partnum = partition(a,begin,end);
		QuickSort_Recursion(a,begin,partnum-1);
		QuickSort_Recursion(a,partnum+1,end);
	} 	
}
int partition(int a[],int begin,int end){
	int key = a[begin];
	while(begin<end){
		while(begin<end&&a[end]>=key)
		--end;
		swap(&a[begin],&a[end]);
		while(begin<end&&a[begin]<=key)
		++begin;
		swap(&a[begin],&a[end]);
	}
	//print(a,10);
	return begin; 
}
//���� 
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp; 
  }
//���ֵ 
void print(int *a,int n){
	int i=0;
	for(i=0;i<n;i++)
	printf("\t%d",a[i]);
}
//��ʼ��ջ
void initstack(stack*s){
	s->top=0;
	s->data=(int*)malloc(sizeof(int)*100);
}
//��ջ
void push(stack*s,int data){
	s->data[s->top++]=data;
} 
//��ջ
void pop(stack*s){
	if(s->top>0) s->top--;
} 
//�п�
int empty(stack *s){
	if(s->top==0) return 1;
	else return 0;
}
//�õ�ͷ 
int top(stack *s){
	return s->data[s->top-1];
} 
//�ǵݹ��������
void QuickSort(int *a,int size){
	stack s;
	initstack(&s);
	int low=0;
	int high=size-1;
	push(&s,low);
	push(&s,high);
	while(!empty(&s)){
		high=top(&s);
		pop(&s);
		low=top(&s);
		pop(&s);
		int par=partition(a,low,high);
		if(low<par-1){
			push(&s,low);
			push(&s,par-1);
		}
		if(high>par+1){
			push(&s,par+1);
			push(&s,high);
		}
	}
	free(s.data);
}
//�����ʼ�� 
void InitList(Node *p)
{
	p->next = NULL;
}
//β�巨 
void Insert(Node *head,int val)
{
	Node *p = head;
	int i;
	for(p;p->next!=NULL;p=p->next);
	Node *q = (Node *)malloc(sizeof(Node));
	q->data=val;
	q->next=NULL;
	p->next = q;
	}
//����ͷ�ڵ㵽data 
int DelHeadNode(Node *p,int *data)
{
	Node *pDel = p->next;
	if (pDel == NULL)
		return 0;
	*data = pDel->data;
	p->next = pDel->next;
	free(pDel);
	pDel = NULL;
	return 1;
}
//�õ������е�������������� 
int GetMaxnum(int *a, int size)
{
	int max = a[0];
	int i = 1;
	for (; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}
//�õ���iλ���� 
int GetNum(int num, int i)  
{
	for(i=i-1;i>0;i--)
	{
		num/=10;
	}
	return num%10;
}
void CountSort(int *a, int size , int max){
	Node head[10];
	int i=0;
	for(i;i<10;i++) InitList(&head[i]); //��ʼ��10��Ͱ
	//��Ͱ
	int num=0;//����max��λ��
	while(max!=0){
		num++;
		max /= 10;
	}
	int count=1;
	for(;count <= num;count++){
		int temp;//���λ���� 
		for(i = 0;i < size;i++){
			temp = GetNum(a[i],count); 
			Insert(&head[temp],a[i]);
		}
		//��Ͱ
		i=0;
		int j=0;//Ͱ��
		while(j<10){
			while(DelHeadNode(&head[j],&a[i]))  //������ɹ�ʱ����1��δ�������0
			i++;
		j++; //Ͱ������ת����һ��Ͱ 
	} 
}
}
void RadixCountSort(int *a,int size)
{
	int max=GetMaxnum(a, size);
	CountSort(a, size , max);
 }
 //����ʱ�� 
	void time1(int n){
		int num=1;
		int i;
		int a[n];
		while(num<=5){
		for(i=0;i<n;i++){
		rand();
		a[i]=rand()%1000;
		}
		if(num==1){
			clock_t start=clock();
			insertSort(a,n);
			clock_t diff= clock()-start;
			printf("insertSort:%dms\n",diff);
		}
		if(num==2){
			clock_t start=clock();
			QuickSort_Recursion(a,0,n);
			clock_t diff= clock()-start;
			printf("QuickSort_Recursion:%dms\n",diff);
		}
		if(num==3){
			clock_t start=clock();
			RadixCountSort(a,n);
			clock_t diff= clock()-start;
			printf("RadixCountSort:%dms\n",diff);
		}
		if(num==4){
			int temp[n];
			clock_t start=clock();
			MergeSort(a,0,n-1,temp);
			clock_t diff= clock()-start;
			printf("MergeSort:%dms\n",diff);
		}
		if(num==5){
			clock_t start=clock();
			QuickSort(a,n);
			clock_t diff= clock()-start;
			printf("QuickSort:%dms\n",diff);
		}
		num++;
	}
}
void time2(){
	int a[100];
	int i=0,j=0,num=1;
	
	while(num<=5){
		int time=0;
		if(num==1){
			for(j=0;j<100000;j++){
				for(i=0;i<100;i++){
				rand();
				a[i]=rand()%1000;
				}
				clock_t start=clock();
				insertSort(a,100);
				clock_t diff= clock()-start;
				time+=diff;		
			}
			printf("insertSort:%dms\n",time);
		}
		if(num==2){
			for(j=0;j<100000;j++){
				for(i=0;i<100;i++){
				rand();
				a[i]=rand()%1000;
				}
				clock_t start=clock();
				QuickSort_Recursion(a,0,100);
				clock_t diff= clock()-start;
				time+=diff;		
			}
			printf("QuickSort_Recursion:%dms\n",time);
		}
		if(num==3){
			for(j=0;j<100000;j++){
				for(i=0;i<100;i++){
				rand();
				a[i]=rand()%1000;
				}
				clock_t start=clock();
				RadixCountSort(a,100);
				clock_t diff= clock()-start;
				time+=diff;		
			}
			printf("RadixCountSort:%dms\n",time);
		}
		if(num==4){
			int temp[100];
			for(j=0;j<100000;j++){
				for(i=0;i<100;i++){
				rand();
				a[i]=rand()%1000;
				}
				clock_t start=clock();
				MergeSort(a,0,99,temp);
				clock_t diff= clock()-start;
				time+=diff;		
			}
			printf("MergeSort:%dms\n",time);
		}
		if(num==5){
			for(j=0;j<100000;j++){
				for(i=0;i<100;i++){
				rand();
				a[i]=rand()%1000;
				}
				clock_t start=clock();
				QuickSort(a,100);
				clock_t diff= clock()-start;
				time+=diff;		
			}
			printf("QuickSort:%dms\n",time);
		}
		num++;
}
}
int main()
{
	//��������
	FILE*fpread = fopen("../src/data.txt","r");
	if(fpread==NULL) 
	{
		printf("δ�ҵ��ļ�");
		return 0; 
	 }
	 int n=0;
	 char ch;
	 //��ȡ���ݸ��� 
	 ch=getc(fpread);
	 while(ch!=EOF){
	 	if(ch==' ') n++;
	 	ch=getc(fpread);
	 }
	 fclose(fpread);
	 FILE*fpread1 = fopen("../src/data.txt","r");
	 int i;
	 int a[n];
	 for(i=0;i<n;i++){
	 	fscanf(fpread1,"%d",&a[i]);
	 }
	 //���򷽷�ѡ��
	 int num;
	 printf("����ָ��\n");
	 printf("1.insertSort\n2.QuickSort_Recursion\n3.RadixCountSort\n4.MergeSort\n5.QuickSort\n0.�˳������޸��ļ�\n");
	 while(scanf("%d",&num)&&num!=0){
	 	for(i=0;i<n;i++){
	 	fscanf(fpread1,"%d",&a[i]);
	 	}
	 	if(num==1){
			 insertSort(a,n);	
		}
		if(num==2){
			 QuickSort_Recursion(a,0,n);	 
		}
		if(num==3){
			 RadixCountSort(a,n);	 
		}
		if(num==4){
			int temp[n];
			 MergeSort(a,0,n,temp);	 
		}
		if(num==5){
			 QuickSort(a,n);	 
		}
		printf("������Ԥ��ǰ10����");
		print(a,10);
		printf("\n");
	}
	FILE*fpWrite = fopen("../src/data.txt","w");
		for(i=0;i<n;i++){
			fprintf(fpWrite,"%d ",a[i]);
		}
	fclose(fpread);
	  
}
