#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max 100
int s[max];
int top=-1;
void push(int x);
void evall(char x);
int res=0;
int main()
{
    char e[max];
    printf("exp: ");
    scanf("%s",e);
    int l=strlen(e);

    for(int i=0; i<l; i++) {
        if(e[i]>='0' && e[i]<='9') {
            push(e[i]);
        }
        if(e[i]=='+' || e[i]=='-' || e[i]=='*' || e[i]=='/' || e[i]=='/' ) {
            evall(e[i]);
        }
    }
    printf("\nresult: %d\n",s[top]);

}
void push(int x)
{
    s[++top]= (int)(x-48);  // type casting to convert from string to int
}
void evall(char x)
{
    int a=s[top--];         //a --> top element
    int b=s[top--];         // b --> next to top 
    //evaluate b operator a

    switch(x) {
    case '+':
        res=b+a;
        break;

    case '-' :
        res=b-a;
        break;
    case '*' :
        res=b*a;
        break;
    case '/' :
        res=b/a;
        break;
    case '^' :
        res=b^a;
        break;
    }
    s[++top]=res;
}
