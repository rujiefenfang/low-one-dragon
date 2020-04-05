#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int data[100];
    int top;
}numstack;//����ջ 

typedef struct
{
    char data[100];
    int top;
}stack; //�ַ�ջ 
//��ʼ��ջ
void nInitstack(numstack *s){
    s->top=0;
}
//��ջ 
void npop(numstack*s,int *c){
    if(s->top==0) printf("ջΪ��");
    else{
        *c=s->data[s->top];
        s->top--;
    }
}
//��ջ
void npush(numstack *s,int c){
    if(s->top==100) printf("ջ����");
    else{
        s->top++;
        s->data[s->top]=c;
    }
}

//��ʼ��ջ
void Initstack(stack *s){
    s->top=0;
}
//�õ�ջ��Ԫ��
int Top(stack s,char *c){
    if(s.top==0) return 0; //��ʱ��0
    else{
        *c=s.data[s.top];
        return 1;
    } 
}
//��ջ
void pop(stack*s,char *c){
    if(s->top==0) printf("ջΪ��");
    else{
        *c=s->data[s->top];
        s->top--;
    }
}
//��ջ
void push(stack *s,char c){
    if(s->top==100) printf("ջ����");
    else{
        s->top++;
        s->data[s->top]=c;
    }
}
//��ջ
int empty(stack s){
    if(s.top==0) return 1;
    else return 0;
}
//��׺ת��׺
void transform(char a[],char b[]){
    stack s;
    Initstack(&s);
    char ch,sh;
    int i=0,j=0;
    ch=s.data[i++];
    while(ch!='\0'){
        switch (ch)
        {
        case '(':
            push(&s,ch);
            break;
        case ')':
            while(Top(s,&sh)&&sh!='('){
                pop(&s,&sh);
                b[j++]=sh;              
            }
            pop(&s,&sh);              //����ǰ���'(' 
            break;
        case '-':
        case '+':                       //'+''-'ͬ��   
            while(Top(s,&sh)&&sh!='('){ //ջ�����ڵ���ʱ����'('���ջ
                pop(&s,&sh);
                b[j++]=sh;
            }
            push(&s,ch);                //����ǿջ���'('��ջ     
            break;
        case '*':
        case '/':
            while(Top(s,&sh)&&sh=='*'||sh=='/'){
                pop(&s,&sh);
                b[j++]=sh;
            }
            push(&s,ch);
            break;
        case ' ' : 
            break;           
        default:
         //����������������ʱ��ǰ����' '����    
            while(ch>='0'&&ch<='9') 
            {   
                b[j++]=ch;
                ch=a[i++]; 
            }
            i--;            //ѭ���ж����һ��               
            b[j++]=' ';
        }
        ch=a[i++];
        
    }
    //����ı�����֮�󣬽�ջ��Ԫ�����ε�����b��
    while(!empty(s))  //��ջʱ�ش�ֵΪ1
    {
        pop(&s,&sh);
        b[j++]=sh;
    }
    b[j]='\0';
    for(i=0;b[i]!='\0';i++)
    b[i]=b[i+1];            //��ȥǰ����һ��' ' 
}

void jisuan(char b[])
{
    numstack s;
    nInitstack(&s);
    int m,n;   //��ʱ����ջ��ֵ
    int ret=0;   //���
    int i=0;
    int j=0;
    while(b[i]!='\0'){
    	if(b[i]!=' '&&b[i]>='0'&&b[i]<='9'){
    		j=j*10+b[i]-'0';
    		i++;
    		continue;
		}
		if(b[i]==' '){
			npush(&s,j);
			i++;
			j=0;
			continue;
		}	
        switch (b[i])
        {
        case '+':
            npop(&s,&m);
            npop(&s,&n);
            ret=m+n;
            npush(&s,ret);
            break;
        case '-':
            npop(&s,&m);
            npop(&s,&n);
            ret=n-m;
            npush(&s,ret);
            break;
        case '*':
            npop(&s,&m);
            npop(&s,&n);
            ret=m*n;
            npush(&s,ret);
            break;
        case '/':
            npop(&s,&m);
            npop(&s,&n);
            ret=n/m;
            npush(&s,ret);
            break;
   
        }
        i++;
    }
    npop(&s,&ret);
    printf("���Ϊ%d",ret);

}
int main(){
    char a[100],b[100];
    printf("��ȷ���Ƿ���ȷ���룬����ȷ���룺\n");
    printf("������׺���ʽ:\n"); 
    gets(a);
    printf("��׺���ʽΪ��\n%s\n",a); 
    printf("��׺���ʽΪ: ");
    transform(a,b);
    printf("\n%s",b);
    printf("\n");
    jisuan(b);

}
