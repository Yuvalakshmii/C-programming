#include <stdio.h>
#include <string.h>
#define n1 50

char stk1[n1];
int top=-1;
void push(char x){
    stk1[++top]=x;
}
int pop(){
    if(top==-1){
        printf("underflow");
    }
    else{
        printf("%c",stk1[top]);
        top--;
    }
}
int main(){
    char s[10];
    scanf("%s",s);
    int l= strlen(s);
    for(int i=0;i<l;i++){
        push(s[i]);
    }
    for (int i=0;i<l;i++){
        pop();
    }
}
