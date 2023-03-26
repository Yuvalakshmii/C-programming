/* 
s [3 4 1 6 7 8]
ns [8 7 6 1 4]
4 1 6 7 8 
*/

output:-
// Queue after enqueue: 5  10  15  20  25  75 
// Queue After Dequeue: 10  15  20  25  75 

#include <stdio.h>
#define max 100
int s[max],ns[max];
int top=-1,i,t=-1;

void push(int x){
    if(top==max-1){
        printf("overflow");
    }
    else{
        s[++top]=x;
    }
}
void pop(){
    if(top==-1){
        printf("underflow");
    }
    else {
        while(top!=0){
        ns[++t]=s[top--];
    }
    }
}
void enqueue(int x1){
    push(x1);
}
void dequeue(){
    pop();
}
void display()	
{
  for (i = 0; i <= top; i++)
    printf (" %d ", s[i]);
}

int main(){
  enqueue(5);
  enqueue(10);
  enqueue(15);
  enqueue(20);
  enqueue(25);
  enqueue(75);
  printf ("Queue after enqueue:");
  display();
  printf ("\nQueue After Dequeue:");
  dequeue();
  for(i=t;i>=0;i--){
        printf(" %d ",ns[i]);
    }
}
