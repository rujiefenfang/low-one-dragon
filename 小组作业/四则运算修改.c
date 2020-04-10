#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	float data[100];
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
void npop(numstack*s,float *c){
    if(s->top==0) printf("ջΪ��");
    else{
        *c=s->data[s->top];
        s->top--;
    }
}
//��ջ
void npush(numstack *s,float c){
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
            while(ch=='.'||ch>='0'&&ch<='9') 
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
    float m,n;   //��ʱ����ջ��ֵ
    float ret=0;   //���
    int i=0,k=0;
    float j=0,p=0;
    while(b[i]!='\0'){
    	if(b[i]!=' '&&b[i]>='0'&&b[i]<='9'){	
			if(k!=0){
				p=p*10+b[i]-'0';
				k++;
			}else
			{
				j=j*10+b[i]-'0';
    			
			}
			i++;
    		continue;
		}
		if(b[i]=='.')k=1;
		if(b[i]==' '){
			for(k;k>1;k--)
			p*=0.1;
			j=j+p;
			npush(&s,j);
			i++;
			k=0;
			p=0;
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
    printf("���Ϊ%f\n",ret);

}
int text(char a[]){
	int i=0;
	for(;a[i]!='\0';i++){
		if(a[i]=='/'&&a[i+1]=='0'&&a[i+2]!='.') return 0;
	}
	return 1;
}
void tiaozheng(char a[])
{	stack s;
    Initstack(&s);
	int i=0,j=0;
	char c[100];
	for(j;a[i]!='\0';j++){
		if(a[i]=='-'){
			if(i==0||a[i-1]>'9'||a[i-1]<'0')
			{	
				push(&s,'(');
				push(&s,'0');
				push(&s,a[i]);
				i++;
				while(a[i]=='.'||a[i]>='0'&&a[i]<='9')
				{
					push(&s,a[i++]);
				}
				push(&s,')');
			}else
				push(&s,a[i++]);
		}else
			push(&s,a[i++]);
	}
	i=s.top-1;
	a[s.top]='\0';
	while(s.top!=0){
		pop(&s,&a[i--]);	
	}
	} 
int main(){
    char a[100],b[100];
	while(1){
	    printf("������׺���ʽ:\n"); 
	    gets(a);
	    //�����������
		tiaozheng(a); 
	    if(text(a)){
		    printf("��׺���ʽΪ��\n%s\n",a); 
		    printf("��׺���ʽΪ: ");
		    transform(a,b);
		    printf("\n%s",b);
		    printf("\n");
		    jisuan(b);
		}
		else printf("���벻�淶���г������\n");
		printf("*********************************************************\n");
		}

}
