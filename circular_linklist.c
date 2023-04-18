// 2 4 5 8
// delete 5
// insert 6,3

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void delete_this(struct node **head,int pos)
{
    struct node *prev,*curr;
    prev=*head;
    curr=*head;
    if(pos==1) {
        *head=curr->link;
        free(curr);
        curr=NULL;
    } else {
        while(pos!=1) {
            prev=curr;
            curr=curr->link;
            pos--;
        }
        prev->link=curr->link;
        free(curr);
        curr=NULL;
    }
}

void insert_any(struct node *head,int data,int pos)
{
    struct node *ptr;
    struct node *temp;
    ptr=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    while(pos>2) {
        ptr=ptr->link;
        pos--;
    }
    temp->link=ptr->link;
    ptr->link=temp;

}

void add_end(struct node *head,int data)
{
    struct node *ptr;
    struct node *temp;
    ptr=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    while(ptr->link !=NULL) {
        ptr=ptr->link;
    }
    ptr->link=temp;
}
void print_list(struct node *head)
{
    struct node *ptr=NULL;
    ptr=head;
    printf("\n");
    while(ptr!=NULL) {
        printf("%d   ",ptr->data);
        ptr=ptr->link;
    }
}

void add_begin(struct node **head,int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    temp->link=*head;
    *head=temp;
    
}

//CIRCULAR SINGLY LINKED LIST

void abics(struct node *head,int data){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    
}


int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=2;
    head->link=head;

    add_end(head,4);
    add_end(head,5);
    add_end(head,8);
    printf("created list: ");
    print_list(head);
    delete_this(&head,3);
     printf("deleted list: ");
    print_list(head);
    insert_any(head,6,3);
     printf("inserted 6 to list: ");
    print_list(head);
    add_begin(&head,1);
     printf("added one at beg of list: ");
    print_list(head);
    abics(head,0);
     printf("circular single list: ");
    print_list(head);

}
