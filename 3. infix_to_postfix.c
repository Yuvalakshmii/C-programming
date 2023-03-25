// 1. using pointers 
// 2. using for loop
// 3. using while loop

#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
}
//-----------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[100];
int top=-1;

void push(char x)
{
    s[++top]=x;
}
char pop()
{
    if(top<0) {
        printf("underflow");
    } else {
        return s[top--];
    }
    return 0;
}
int prio(char x)
{
    if(x=='(') {
        return 0;
    }
    if(x=='+' || x=='-') {
        return 1;
    }
    if(x=='*' || x=='/') {
        return 2;
    }
    if(x=='^') {
        return 3;
    }
}

int main()
{
    char p;
    int i=0;
    char e[100];
    printf("enter: ");
    scanf("%s",e);
    int l=strlen(e);
    // for(int i=0; i<l; i++) {

    //     if(isalnum(e[i])) {
    //         printf("%c",e[i]);
    //     }
    //     else if(e[i]=='(') {
    //         push(e[i]);
    //     }
    //     else if(e[i]==')') {
    //         while((p=pop())!= '(') {
    //             printf("%c",p);
    //         }
    //     } 
    //     else {
    //         if(prio(s[top]) >= prio(e[i])) {
    //             printf("%c",pop());
    //         } 
    //         push(e[i]);
    //     }
    // }
    while(i<l){
        if(isalnum(e[i])){
            printf("%c",e[i]);
        }
        else if(e[i]=='(') {
            push(e[i]);
        }
        else if(e[i]==')') {
            while((p=pop())!= '(') 
                printf("%c",p);}
        else if(prio(s[top]) >= prio(e[i])) {
                 printf("%c",pop());
        }
        
        else{
            push(e[i]);
        }
      i++;  
    }
    while(top!=-1) {
        printf("%c",pop());
    }
}
