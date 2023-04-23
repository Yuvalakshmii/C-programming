OUTPUT:
circular single list: 
2   4   5   8   
added one at beg of list: 
1   2   4   5   8   
add 6 at 3rd pos to list: 
1   2   6   4   5   8   

no of nodes: 4

deleted element at pos 3: 
1   2   4   5   8   
delete element at front: 
2   4   5   8   
delete element at end: 
2   4   5   
delete element 4: 
2   5   

yes!,found 5 in linked list


---------------------------------------
CODE:-
    
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void delval(struct node *tail,int val)
{
    struct node *prev,*curr;
    prev=tail->link;
    curr=tail->link;
    if(curr->data==val) {
        tail->link=curr->link;
    } else {
        while(curr->data!=val) {
            prev=curr;
            curr=curr->link;
        }
        prev->link=curr->link;

    }
}

void delete_by_pos(struct node *tail,int pos)
{
    struct node *prev,*curr;
    prev=tail->link;
    curr=tail->link;
    if(pos==1) {
        tail->link=curr->link;
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

void delend(struct node *tail)
{
    struct node *curr;
    curr=tail->link;
    while(curr->link!=tail) {
        curr=curr->link;
    }
    curr->link=tail->link;

}

void add_at_pos(struct node *tail,int data,int pos)
{
    struct node *ptr;
    struct node *temp;
    ptr=tail->link;
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

struct node* addend(struct node* tail,int data)
{

    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=tail->link;
    tail->link=temp;

    return temp;
}

void add_begin(struct node *tail,int data)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=tail->link;
    tail->link=temp;

}

void print_list(struct node *tail)
{
    struct node *ptr=tail->link;
    printf("\n");
    do {
        printf("%d   ",ptr->data);
        ptr=ptr->link;
    } while(ptr!=tail->link);
}

void count_nodes(struct node *tail)
{
    int n=0;
    struct node *ptr=tail->link;
    do {
        n++;
        ptr=ptr->link;
    } while(ptr->link!=tail);
    printf("\n\nno of nodes: %d\n",n);
}

void search_ele(struct node *tail,int data)
{

    struct node *curr;
    curr=tail->link;
    if(curr->data==data) {
        printf("\nyes!,found %d at position 1",data);
    } 
    else{
        while(curr->data!=data) {
            curr=curr->link;
        }
        if(curr->data=data){
        printf("\n\nyes!,found %d in linked list",data);
    }
        else{
            printf("no!");
        }

}
}

int main()
{
    int n=0;
    struct node *tail=malloc(sizeof(struct node));
    tail->data=2;
    tail->link=tail;

    tail=addend(tail,4);
    tail=addend(tail,5);
    tail=addend(tail,8);
    printf("circular single list: ");
    print_list(tail);
    add_begin(tail,1);
    printf("\nadded one at beg of list: ");
    print_list(tail);
    add_at_pos(tail,6,3);
    printf("\nadd 6 at 3rd pos to list: ");
    print_list(tail);
    
    count_nodes(tail);
    
    delete_by_pos(tail,3);
    printf("\ndeleted element at pos 3: ");
    print_list(tail);
    delete_by_pos(tail,1);
    printf("\ndelete element at front: ");
    print_list(tail);
    delend(tail);
    printf("\ndelete element at end: ");
    print_list(tail);
    delval(tail,4);
    printf("\ndelete element 4: ");
    print_list(tail);
    search_ele(tail,5);
}
