#include <stdio.h>
#include <math.h>
char a,b,c;
void move(int n,char s,char d, char a)
{

    if(n==1) {
        printf("\nmove 1 from %c to %c",s,d);
        return;
    }
    move(n-1,s,a,d);
    printf("\nmove %d from %c to %c",n,s,d);
    move(n-1,a,d,s);

}
int main()
{
    int n;
    printf("enter n: ");
    scanf("%d",&n);
    int n1=pow(2,n)-1;
    printf("there are %d steps:-",n1);
    move(n,'a','c','b');
}


output:-
  enter n: 3
there are 7 steps:-
move 1 from a to c
move 2 from a to b
move 1 from c to b
move 3 from a to c
move 1 from b to a
move 2 from b to c
move 1 from a to c
