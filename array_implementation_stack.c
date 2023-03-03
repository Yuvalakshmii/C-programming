//STACK IMPLEMENTATION USING ARRAY #include <stdio. h> #define MAX 15
int main(){
int a [MAX]; 
int i,j,n;
int top=-1;
while(1) {
    printf("\n1.push () \n2.pop () \n3. peek() \n4. display\n5.exit\n");
    printf ("enter your choice (1/2/3/4/5): ");
    scanf ("'od" , &n) ;
  
    if (n==5){
      printf("end\n");
      break;
}
    switch(n){
      case (1):
            if(top==(MAX-1) ){
                  printf("stack is full!\n");
            return 0;
}
            printf("enter number to insert: ");
            scanf ("8d" ‚&i) ; top++;
            a[top]=i;
            break;
      case (2):
            if (top==-1){
              printf ("Stack underflow! \n");
              break;
}
              printf("popped element is: 8d\n ", a [top]);
              top--; 
              break;
      case (3):
            if(top==-1){
                printf("Stack underflow!\n");
                break;
            }
            printf("top value is %d\n", top);
            printf("peeked element is %d\n",a[top]);
            break;

        case (4):
            if(top==-1){
                printf("Stack underflow!\n");
                break;
            }
            for(i=top;i>=0;i--){
                printf("%d\n",a[i]);
            }    
            break;
        default:
           printf("invalid choice!");  
           break;      
            }
    }
    return 0;

}
  
      
