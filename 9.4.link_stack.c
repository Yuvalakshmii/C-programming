
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
}*top=NULL;

int isemp(){
    if(top==NULL){
        printf("stack underflow");
    }
    else{
        return 0;
    }
}
void push(int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=top;
    top=temp;
    
}
int pop(){
    if(isemp()){
        exit(1);
    }
    else{
    struct node *temp=top;
    int val=temp->data;;
    top=top->link;
    free(temp);
    temp=NULL;
    return val;
}
}
void print(){
    if(isemp()){
        exit(1);
    }
    else{
        struct node *temp=top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
}
}
int main(){
    int val=0;
    push(3);
    push(6);
    push(9);
    push(2);
    printf("\ncreated stack using linked list: ");
    print();
    printf("\npopped element: ");
    int t=pop();
    printf("%d", t);
    printf("\nstack after popping: ");
    print();
}
