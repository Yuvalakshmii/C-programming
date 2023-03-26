//dont forget --  push(), pop(),prio(),main(),else if with right indendation, int prio(char x) {if(x==')') return 0};
//(a-b)*c
// c*)b-a(
//s[ *)-(
//pe[ cba-* ]
// *-abc
// first rev given string -- do postfix -- rev
// push(+,-,*,/)
//pop - alphanum

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
    }
    else{
    return s[top--];
}
}

int prio(char x)
{
    if(x==')' || x=='\0') {
        return 0;
    }
    else if(x=='+' || x=='-') {
        return 1;
    }
    else if(x=='*' || x=='/') {
        return 2;
    }
    else if(x=='^') {
        return 3;
    }
}

int main()
{
    char re[100], pe[100];
    char p;
    int t=-1;
    printf("exp: ");
    scanf("%s",re);
    int l=strlen(re);
    for(int i=l-1; i>=0; i--) {
        if(isalnum(re[i])) {
            pe[++t]=re[i];
        } 
        else if(re[i]==')') {
            push(re[i]);
        } 
        else if(re[i]=='(') {
            while((p=pop())!=')') {
                pe[++t]=p;
            }
        } 
        else {
            while(prio(s[top])>prio(re[i])) {
            pe[++t]=pop();
        } 
            push(re[i]);
        
         }
    }
    while(top!=-1) {
        pe[++t]=pop();
    }
    for(int i=(strlen(pe))-1; i>=0; i--){
        printf("%c ",pe[i]);
    }
}

