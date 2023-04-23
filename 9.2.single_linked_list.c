280 MAIN PROGRAM
/*
1.count_of_nodes
2.print data
3.insert
4.delete

*/


// this is by creating each pointer for each node 
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void count_of_nodes();
void printdata();
int main()
{
    struct node *head= malloc(sizeof(struct node));
        head->data=45;
        head->link=NULL;
 //       printf("%d",head->data);
 //       printf("%p",&head);

    struct node *curr=malloc(sizeof(struct node));
        curr->data=98;
        curr->link=NULL;
        head->link=curr;
//      printf("\n%p",head->link);

  curr=malloc(sizeof(struct node));
  curr->data=3;
  curr->link=NULL;
  head->link->link=curr;
 //   printf("\n%p",head->link->link);
    count_of_nodes(head);
    printdata(head);
}
void count_of_nodes(struct node *head)
{

    int count=0;
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL) {
        count++;
        ptr=ptr->link;
    }

    printf("no of nodes : %d\n",count);
}

void printdata(struct node *head){
struct node *ptr=NULL;
ptr=head;
printf("elements in linked list is: ");
while(ptr != NULL){
    printf("%4d",ptr->data);
    ptr = ptr->link;
    
}}




//another method --- insertion by (ADDING AT END)

// create 2 4 6 8 10 12 14
// nodes count
// del 5
// insert 9 , at 5
// printing --> 2 4 6 8 9 12 14
// insert at begin


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void add_end(struct node *head,int d)
{
    struct node *ptr;
    struct node *temp;
    ptr=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->link=NULL;

    while(ptr->link !=NULL) {
        ptr=ptr->link;
    }
    ptr->link=temp;
}

void insert_at(struct node *head,int d,int pos)
{
    struct node *ptr=head;
    struct node *ptr2;
    ptr2=(struct node*)malloc(sizeof(struct node));
    ptr2->data=d;
    ptr2->link=NULL;

    while(pos !=2) {
        ptr=ptr->link;
        pos--;
    }
    ptr2->link=ptr->link;
    ptr->link=ptr2;

}

void delete_this(struct node **head,int pos)
{
    struct node *prev=*head;
    struct node *curr=*head;

    //to check empty list
    if(*head==NULL) {
        printf("link is empty");
    } else if(pos==1) {
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

void count_nodes(struct node *head)
{
    struct node *ptr=NULL;
    ptr=head;
    int count=0;
    while(ptr!=NULL) {
        count++;
        ptr=ptr->link;
    }
    printf("\nno of nodes: %d",count);
}

void add_begin(struct node **head,int d)
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=d;
    ptr->link=NULL;
    
    ptr->link=*head;
    *head=ptr;

}

void print_list(struct node *head)
{
    struct node *ptr=NULL;
    ptr=head;
    printf("\n");
    while(ptr!=NULL) {
        printf("%3d",ptr->data);
        ptr=ptr->link;
    }
}

int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=2;
    head->link=NULL;

    add_end(head,4);
    add_end(head,6);
    add_end(head,8);
    add_end(head,10);
    add_end(head,12);
    add_end(head,14);
    printf("created list:-");
    print_list(head);
    count_nodes(head);
    delete_this(&head,5);
    printf("\nafter deleting node:-");
    print_list(head);
    insert_at(head,9,5);
    printf("\nafter insertion:-");
    print_list(head);
    count_nodes(head);
    add_begin(&head,1);
    print_list(head);
    count_nodes(head);


}


//this is by getting input from user and printing list with no of nodes
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void printdata(struct node *head)
{
    struct node *pt=NULL;
    pt=head;
    printf("elements in linked list is: ");
    while(pt != NULL) {
        printf("%4d",pt->data);
        pt = pt->link;
    }
}

void add_end(struct node *head,int d)
{
    struct node *ptr;
    struct node *temp;
    ptr=head;
    temp=malloc(sizeof(struct node));
    temp->data=d;
    temp->link=NULL;

    while(ptr->link!=NULL) {
        ptr=ptr->link;
    }
    ptr->link=temp;
}

void cou(struct node *head){
    int cou=0;
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        cou++;
        ptr=ptr->link;
    }
    printf("\nno of nodes: %d",cou);
}

int main()
{
    int a[100];
    int n;
    printf("how many elements: ");
    scanf("%d",&n);
    printf("enter elements:-\n ");

    for(int i=0; i<n; i++) {
        printf("%d :",i);
        scanf("%d",&a[i]);
    }

    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=a[0];
    head->link=NULL;
    for(int i=1; i<n; i++) {
        add_end(head,a[i]);
    }
    printdata(head);
    cou(head);
}



//COMPLETE PROGRAM 

// 2 4 5 8
// delete 3rd pos
// insert 6 at 3rd pos
// add one at front
// del one at front
// del 8 at end
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void delbyvalue(struct node **head,int val)
{
    struct node *prev,*curr;
    prev=*head;
    curr=*head;
    if(curr->data==val){
        *head=curr->link;
        free(curr);
        curr=NULL;
    }
    else{
        while(curr->data!=val){
        prev=curr;
        curr=curr->link;
         }           
        prev->link=curr->link;
        free(curr);
        curr=NULL;

    }
}

void delete_by_pos(struct node **head,int pos)
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

void delend(struct node *head){
    struct node *prev,*curr;
    prev=head;
    curr=head;
    while(curr->link!=NULL){
        prev=curr;
        curr=curr->link;
    }
    prev->link=NULL;
    free(curr);
    curr=NULL;
    
    
}

void add_at_pos(struct node *head,int data,int pos)
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

int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=2;
    head->link=NULL;

    add_end(head,4);
    add_end(head,5);
    add_end(head,8);
    printf("created list: ");
    print_list(head);
    delete_by_pos(&head,3);
    printf("\ndeleted element at pos 3: ");
    print_list(head);
    add_at_pos(head,6,3);
    printf("\ninserted 6 to list: ");
    print_list(head);
    add_begin(&head,1);
    printf("\nadded one at beg of list: ");
    print_list(head);
    delbyvalue(&head,1);
    printf("\nafter deleting value 1");
    print_list(head);
    delend(head);
    printf("\ndelete element at end");
    print_list(head);
}





