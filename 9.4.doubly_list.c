output:
doubly linked list:    1 2 3 4 5 
adding 1 at front:   1 1 2 3 4 5 
adding at pos 3:     1 1 9 2 3 4 5 
delete at end:       1 1 9 2 3 4 
delete at front:     1 9 2 3 4 
delete at pos 3:     1 9 3 4 


#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

struct node* addToempty(struct node* head, int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node* addbeg(struct node* head, int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head->prev=temp;
    head = temp;
    return head;
}

void addend(struct node* head, int data)
{
    struct node *ptr=head;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data = data;
    temp->next = NULL;

    while(ptr->next!=NULL) {
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;

}

void addbypos(struct node* head, int data,int pos)
{
    struct node *ptr2,*ptr=head;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data = data;
    temp->next = NULL;
    
    while(pos>2){
        ptr=ptr->next;
        pos--;
    }
    ptr2=ptr->next;
    ptr->next=temp;
    temp->prev=ptr;
    temp->next=ptr2;
    ptr2->prev=temp;
    
    

}

void delend(struct node* head)
{
    struct node *pre,*curr;
    pre=head;
    curr=head;

    while(curr->next!=NULL) {
        pre=curr;
        curr=curr->next;
    }
    pre->next=NULL;
    free(curr);
    curr=NULL;
}

struct node* delfront(struct node* head)
{
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    ptr=NULL;
    head->prev=NULL;
    return head;

}

struct node* delatpos(struct node* head,int pos)
{
    struct node *pre,*curr;
    pre=head;
    curr=head;
    if(pos==1) {
        head=head->next;
        free(curr);
        curr=NULL;
        head->prev=NULL;
        return head;
    }
    while(pos>1) {
        pre=curr;
        curr=curr->next;
        pos--;
    }
    pre->next=curr->next;
    free(curr);
    curr=NULL;
    return head;
}

void print(struct node* head)
{
    struct node* ptr = head;
    while(ptr!=NULL) {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    struct node* head;
    head=addToempty(head,1);
    addend(head,2);
    addend(head,3);
    addend(head,4);
    addend(head,5);
    printf("doubly linked list:    ");
    print(head);
    printf("\nadding 1 at front:   ");
    head=addbeg(head,1);
    print(head);
    printf("\nadding at pos 3:     ");
    addbypos(head,9,3);
    print(head);
    printf("\ndelete at end:       ");
    delend(head);
    print(head);
    printf("\ndelete at front:     ");
    head=delfront(head);
    print(head);
    printf("\ndelete at pos 3:     ");
    head=delatpos(head,3);       
    print(head);       
}
