output:
// Queue: 5  10  15  20  25 
// Queue After Dequeue: 25  20  15  10  5 
  
#include <stdio.h>
#include <stdlib.h>

#define N 20			//defining the size of queue

int s[N], top = -1;

int pop ()				//function to remove an element from stack
{
 // return s[top--];
 printf(" %d ",s[top]);
 top--;
}

void push (int x)			//function to insert an element into stack
{
  if (top == N - 1)
    printf ("Stack is Full");
  else
    {
      s[++top]=x;
    }
}

void enqueue (int x)		
{
  push (x);
}

void display ()			//function to print elements of a queue
{
  int i;
  for (i = 0; i <= top; i++)
    printf (" %d ", s[i]);
}

int dequeue ()		
{
  int data, res;
  if (top == -1)
    printf ("Queue is Empty");
  else if (top == 0)
    return pop ();
  data = pop ();
  res = dequeue ();
  push (data);
  return res;

}

int main ()
{
  enqueue (5);
  enqueue (10);
  enqueue (15);
  enqueue (20);
  enqueue (25);
  printf ("Queue:");
  display ();
  printf ("\nQueue After Dequeue:");
  dequeue ();
 // display ();
}
    
