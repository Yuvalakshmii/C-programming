#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
}*top=NULL;

struct node* delfront(struct node *head)
{
    struct node *ptr=head;
    head=head->link;
    free(ptr);
    ptr=NULL;
    return head;
}

struct node* addfront(struct node *head,int data)
{
    struct node *ptr=head;
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->link=ptr;
    head=temp;
    return head;

}

// void delend(struct node *head)
// {
//     struct node *ptr=head;
//     struct node *pre=head;
//     while(ptr->link!=NULL) {
//         pre=ptr;
//         ptr=ptr->link;
//     }
//     pre->link=NULL;
//     free(ptr);
//     ptr=NULL;
// }

// void addend(struct node *head,int data)
// {
//     struct node *ptr=head;
//     struct node *temp=malloc(sizeof(struct node));
//     temp->prev=NULL;
//     temp->data=data;
//     temp->link=NULL;

//     while(ptr->link!=NULL) {
//         ptr=ptr->link;
//     }
//     ptr->link=temp;
//     temp->prev=ptr;


// }

void p(struct node *head)
{
    struct node *ptr=head;
    while(ptr!=NULL) {
        //  printf("\n");
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}

int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=5;
    head->link=NULL;

    // addend(head,4);
    // addend(head,3);
    // addend(head,2);
    // p(head);
    // delend(head);
    // printf("\n");
    // p(head);
    head=addfront(head,23);
    head=addfront(head,7);
    head=addfront(head,68);
    printf("\n");
    p(head);
    head=delfront(head);
    printf("\n");
    p(head);
    
}

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
