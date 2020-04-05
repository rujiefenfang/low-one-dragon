#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int data[100];
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
void npop(numstack*s,int *c){
    if(s->top==0) printf("栈为空");
    else{
        *c=s->data[s->top];
        s->top--;
    }
}
//入栈
void npush(numstack *s,int c){
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
            while(ch>='0'&&ch<='9') 
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
    int m,n;   //临时出入栈的值
    int ret=0;   //结果
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
    printf("结果为%d",ret);

}
int main(){
    char a[100],b[100];
    printf("无确认是否正确输入，请正确输入：\n");
    printf("输入中缀表达式:\n"); 
    gets(a);
    printf("中缀表达式为：\n%s\n",a); 
    printf("后缀表达式为: ");
    transform(a,b);
    printf("\n%s",b);
    printf("\n");
    jisuan(b);

}
