//dont forget : top=-1, int i,case -- (break, no return usage)
//-+456
//654
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int s[100];
int top=-1;

void push(int x){
    s[++top]=(int)(x-48);
}
int pop(){
    if(top<0){
        printf("underflow");
    }
    return s[top--];
}

int main(){
    char e[100];
    int res=0;
    printf("exp: ");
    scanf("%s",e);
    int l=strlen(e);
    for(int i=l-1;i>=0;i--){
        if(isdigit(e[i])){
            push(e[i]);
        }
        else if(e[i]=='+' ||e[i]=='-' || e[i]=='*' ||e[i]=='/'){
            int a=pop();
            int b=pop();
            switch(e[i]){
                case '+':
                res=a+b;
                break;
                case '-':
                res=a-b;
                break;
                case '*':
                res=a*b;
                break;
                case '/':
                res=a/b;
                break;
            }
            s[++top]=res;
        }
    }
    printf("%d",s[top]);
}
