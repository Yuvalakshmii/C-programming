#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE], top = -1;
int queue[MAX_SIZE], front = 0, rear = -1;

// Function to check if stack is empty
int isStackEmpty() {
    return top == -1;
}

// Function to check if queue is empty
int isQueueEmpty() {
    return front > rear;
}

// Function to push element into stack
void push(int item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

// Function to pop element from stack
int pop() {
    if (isStackEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// Function to enqueue element into queue
void enqueue(int item) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    queue[++rear] = item;
}

// Function to dequeue element from queue
int dequeue() {
    if (isQueueEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

// Function to empty the contents of stack and insert them into queue
void fillQ_withS() {
    while (!isStackEmpty()) {
        int item = pop();
        enqueue(item);
    }
}

// Function to fill the stack with the elements deleted from the queue
void fillS_withQ() {
    while (!isQueueEmpty()) {
        int item = dequeue();
        push(item);
    }
}

// Function to print the contents of stack
void printStack() {
    printf("Stack: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Function to print the contents of queue
void printQueue() {
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    // Push elements into stack
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    // Print initial contents of stack
    printStack();

    // Empty stack and insert elements into queue
    fillQ_withS();

    // Print contents of queue after insertion
    printQueue();

    // Fill stack with elements deleted from queue
    fillS_withQ();

    // Print contents of stack after filling
    printStack();

    return 0;
}
