#include "AQueue.h"
int main()
{
	AQueue q;
	q.data[0]=NULL;
	int i,j=0;
	screen();
	while(printf("������ָ�\n")&&scanf("%d",&i)&&i!=0)
	{
		j++;
		if(j%5==0) screen();
		if(i==1){
			InitAQueue(&q);
			printf("��ʼ���ɹ�!\n");
		}
		if(i==2){
			if(q.data[0]==NULL) {
				printf("����δ��ʼ��\n");
				continue; 
			} 
			IsEmptyAQueue(&q);					
		} 
		if(i==3){
			if(q.data[0]==NULL) {
				printf("����δ��ʼ��\n");
				continue; 
			} 
			IsFullAQueue(&q);			
		}
		if(i==4){
		  //����һ�����뺯��
		  	if(q.data[0]==NULL) {
				printf("����δ��ʼ��\n");
				continue; 
			}			
			push(&q);		 						
		}
		if(i==5){
			//���ͷ����Ԫ��
			if(q.data[0]==NULL) {
				printf("����δ��ʼ��\n");
				continue; 
			}
			if(q.length==0){
				printf("����Ϊ��\n");
				continue; 
			}
			int k=q.type[q.front];
			gethead(q,k);
			printf("\n"); 
		}
		if(i==6){//���г��� 
			if(q.data[0]==NULL) {
				printf("����δ��ʼ��\n");
				continue; 
			}
			printf("���г���Ϊ%d\n",LengthAQueue(&q));
		}
		if(i==7){//���� 
			if(q.data[0]==NULL) {
				printf("����δ��ʼ��\n");
				continue; 
			}
			if(DeAQueue(&q)) printf("���ӳɹ�\n");
			else printf("����Ϊ�ջ���δ��ʼ��\n"); 
		}
		if(i==8){//��ն��� 
			ClearAQueue(&q);
			printf("\n");
		}
		if(i==9){//�������� 
			if(q.data[0]==NULL) {
				printf("����δ��ʼ��\n");
				continue; 
			}
			TraverseAQueue(&q, APrint);
		}
		if(i==10){//���ٶ��� 
			DestoryAQueue(&q);
	}
	if(j%5==0&&q.data[0]!=NULL) printf("���еĳ���Ϊ%d,��ʣ%d���ռ�\n",q.length,MAXQUEUE-q.length);
	}
}
