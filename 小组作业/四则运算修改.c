#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
	float data[100];
    int top;
}numstack;//数字栈 

typedef struct
{
    char data[100];
    int top;
}stack; //字符栈 
//初始化栈
void nInitstack(numstack *s){
    s->top=0;
}
//出栈 
void npop(numstack*s,float *c){
    if(s->top==0) printf("栈为空");
    else{
        *c=s->data[s->top];
        s->top--;
    }
}
//入栈
void npush(numstack *s,float c){
    if(s->top==100) printf("栈满了");
    else{
        s->top++;
        s->data[s->top]=c;
    }
}

//初始化栈
void Initstack(stack *s){
    s->top=0;
}
//得到栈顶元素
int Top(stack s,char *c){
    if(s.top==0) return 0; //空时回0
    else{
        *c=s.data[s.top];
        return 1;
    } 
}
//出栈
void pop(stack*s,char *c){
    if(s->top==0) printf("栈为空");
    else{
        *c=s->data[s->top];
        s->top--;
    }
}
//入栈
void push(stack *s,char c){
    if(s->top==100) printf("栈满了");
    else{
        s->top++;
        s->data[s->top]=c;
    }
}
//空栈
int empty(stack s){
    if(s.top==0) return 1;
    else return 0;
}
//中缀转后缀
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
            pop(&s,&sh);              //弹出前面的'(' 
            break;
        case '-':
        case '+':                       //'+''-'同级   
            while(Top(s,&sh)&&sh!='('){ //栈顶大于等于时，除'('外出栈
                pop(&s,&sh);
                b[j++]=sh;
            }
            push(&s,ch);                //如果是空或者'('入栈     
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
         //这里设置连续数字时用前后都是' '隔开    
            while(ch=='.'||ch>='0'&&ch<='9') 
            {   
                b[j++]=ch;
                ch=a[i++]; 
            }
            i--;            //循环中多加了一个               
            b[j++]=' ';
        }
        ch=a[i++];
        
    }
    //输入的遍历完之后，将栈中元素依次弹出到b中
    while(!empty(s))  //空栈时回代值为1
    {
        pop(&s,&sh);
        b[j++]=sh;
    }
    b[j]='\0';
    for(i=0;b[i]!='\0';i++)
    b[i]=b[i+1];            //除去前面多的一个' ' 
}

void jisuan(char b[])
{
    numstack s;
    nInitstack(&s);
    float m,n;   //临时出入栈的值
    float ret=0;   //结果
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
    printf("结果为%f\n",ret);

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
	    printf("输入中缀表达式:\n"); 
	    gets(a);
	    //调整负数情况
		tiaozheng(a); 
	    if(text(a)){
		    printf("中缀表达式为：\n%s\n",a); 
		    printf("后缀表达式为: ");
		    transform(a,b);
		    printf("\n%s",b);
		    printf("\n");
		    jisuan(b);
		}
		else printf("输入不规范，有除零情况\n");
		printf("*********************************************************\n");
		}

}
