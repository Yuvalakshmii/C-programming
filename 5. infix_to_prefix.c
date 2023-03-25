//dont forget --  push(), pop(),prio(),main()
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
    if(x=='(') {
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
    int i=0;
    printf("exp: ");
    scanf("%s",re);
    int l=strlen(re);
    for(int i=l-1; i>=0; i--) {
        if(isalnum(re[i])) {
            pe[++top]=re[i];
        } else if(re[i]==')') {
            push(re[i]);
        } else if(re[i]=='(') {
            while((p=pop())!=')') {
                pe[++top]=p;
            }
        } else if(prio(s[top])>prio(re[i])) {
            pe[++top]=pop();
        } else {
            push(re[i]);
        }
    }
    while(top!=-1) {
        pe[++top]=pop();
    }
    for(int i=l-1; i>=0; i--){
        printf("%c",pe[i]);
    }
}
