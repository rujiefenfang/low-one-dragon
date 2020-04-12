#include "LQueue.h"
int main()
{
	LQueue q;
	int i,j;
	j=0;
	q.front=q.rear=NULL; //未初始化前
	screen();
	while(printf("请输入指令：\n")&&scanf("%d",&i)&&i!=0){
		j++;
		if(j%5==0) screen();
		switch(i){
			case 1:{//初始化 
				InitLQueue(&q);
				break;
			}
			case 2:{//销毁
				if(q.front==NULL) {
					printf("队列未初始化\n");
					break;
				} 
				DestoryLQueue(&q);
				printf("销毁成功\n"); 
				break;
			}
			case 3:{//判空 
				if(q.front==NULL) {
					printf("队列未初始化\n");
					break;
				}
				if(IsEmptyLQueue(&q)) printf("队列为空\n");
				else printf("队列不为空\n");  
				break;
			}
			case 4:{//得到头元素 
				if(q.front==NULL) {
					printf("队列未初始化\n");
					break; 
				}
				if(q.front->next==NULL){
					printf("队列为空\n");
					break;
				} 
				int j=q.front->next->type;
				printf("头队列元素为：");
				gethead(&q,j); 
				break;
			}
			case 5:{//队列长度 
				if(q.front==NULL) {
					printf("队列未初始化\n");
					break; 
				}
				printf("队列长度为：%d",LengthLQueue(&q));
				break;
			}
			case 6:{//入队 
				if(q.front==NULL) {
					printf("队列未初始化\n");
					break; 
				}
				push(&q);
				break;
			}
			case 7:{//出队 
				if(q.front==NULL) {
					printf("队列未初始化\n");
					break; 
				}
				if(q.front->next==NULL){
					printf("队列为空\n");
					break;
				}
				DeLQueue(&q);
				printf("出队成功\n"); 
				break;
			}
			case 8:{//清空 
				if(q.front==NULL) {
					printf("队列未初始化\n");
					break; 
				}
				ClearLQueue(&q);
				printf("清空成功\n");
				break;
			}
			case 9:{//遍历 
				if(q.front==NULL) {
					printf("队列未初始化\n");
					break; 
				}
				if(q.front->next==NULL){
					printf("队列为空\n");
					break;
				}
				printf("各个元素为："); 
				TraverseLQueue(&q, LPrint);
				break;
			}
		}
	} 
    
}
