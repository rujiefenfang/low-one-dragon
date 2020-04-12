#include "LQueue.h"
int main()
{
	LQueue q;
	int i,j;
	j=0;
	q.front=q.rear=NULL; //δ��ʼ��ǰ
	screen();
	while(printf("������ָ�\n")&&scanf("%d",&i)&&i!=0){
		j++;
		if(j%5==0) screen();
		switch(i){
			case 1:{//��ʼ�� 
				InitLQueue(&q);
				break;
			}
			case 2:{//����
				if(q.front==NULL) {
					printf("����δ��ʼ��\n");
					break;
				} 
				DestoryLQueue(&q);
				printf("���ٳɹ�\n"); 
				break;
			}
			case 3:{//�п� 
				if(q.front==NULL) {
					printf("����δ��ʼ��\n");
					break;
				}
				if(IsEmptyLQueue(&q)) printf("����Ϊ��\n");
				else printf("���в�Ϊ��\n");  
				break;
			}
			case 4:{//�õ�ͷԪ�� 
				if(q.front==NULL) {
					printf("����δ��ʼ��\n");
					break; 
				}
				if(q.front->next==NULL){
					printf("����Ϊ��\n");
					break;
				} 
				int j=q.front->next->type;
				printf("ͷ����Ԫ��Ϊ��");
				gethead(&q,j); 
				break;
			}
			case 5:{//���г��� 
				if(q.front==NULL) {
					printf("����δ��ʼ��\n");
					break; 
				}
				printf("���г���Ϊ��%d",LengthLQueue(&q));
				break;
			}
			case 6:{//��� 
				if(q.front==NULL) {
					printf("����δ��ʼ��\n");
					break; 
				}
				push(&q);
				break;
			}
			case 7:{//���� 
				if(q.front==NULL) {
					printf("����δ��ʼ��\n");
					break; 
				}
				if(q.front->next==NULL){
					printf("����Ϊ��\n");
					break;
				}
				DeLQueue(&q);
				printf("���ӳɹ�\n"); 
				break;
			}
			case 8:{//��� 
				if(q.front==NULL) {
					printf("����δ��ʼ��\n");
					break; 
				}
				ClearLQueue(&q);
				printf("��ճɹ�\n");
				break;
			}
			case 9:{//���� 
				if(q.front==NULL) {
					printf("����δ��ʼ��\n");
					break; 
				}
				if(q.front->next==NULL){
					printf("����Ϊ��\n");
					break;
				}
				printf("����Ԫ��Ϊ��"); 
				TraverseLQueue(&q, LPrint);
				break;
			}
		}
	} 
    
}
