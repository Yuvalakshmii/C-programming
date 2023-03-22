#include <stdio.h>
#include <stdlib.h>

#define s 100
#define s1 100
int i, n, num;
int stk[s];
int stk2[s1];

int top = -1;

void push(int item) {
    if (top == s - 1) {
        printf("Stack Overflow");
        return;
    }
    stk[++top] = item;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    for (int i = 0; i < n; i++) {
     int t=stk[top];
     stk2[i]=t;
     top--;
    }
}

int main() {
 
    printf("Enter the number of students: ");
    scanf("%d", &n);

    printf("Enter the register numbers of the students:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        push(num);
    }
    //popping all & storing into another array 
    pop();
     //popping from stk2 
    printf("first 3 students who submitted their assignment:\n");
    for(i=n-1;i>=n-3;i--){
        printf("%4d",stk2[i]);
    }
}
    



output:
// Enter the number of students: 7
// Enter the register numbers of the students:
// 211
// 124
// 136
// 13
// 45
// 124
// 12
// first 3 students who submitted their assignment:
//  211 124 136
