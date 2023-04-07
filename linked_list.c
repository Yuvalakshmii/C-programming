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
