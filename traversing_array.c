#include <stdio.h>
int main(){
// SIZE 
int i,j=0,a[]= {3,4,6,8,2,9};
int n= sizeof(a)/sizeof(a[0]); 
printf("\n#size of array: sd\n\n", n) ;

//TRAVERSING
printf("#array traversing:-\n");
for(i=0; i‹n; i++) {
printf(" arr[%d]= %d\n", ¡,a[i]);
}

// SEARCH
printf("\n#searching an element:-\n");
int v1;
printf("enter element to search: ");
scanf ("%d" , &v1);
while( j< n) {
if(a[i] == v1){
break;
printf("found element %d is at position %d\n", v1, j+1);
}
else j=i+1;

}
printf("\n#Inserting an element:-\n");

// INSERTION
int p,v;
printf ("enter index of an inserting element: "); 
scanf ("%d" , &p) ;
printf("enter value of an inserting element: ");
scanf ("%d" ‚&v);
n=n+1; 
j=n;
while(j>=p){
a[j+1]=a[j]; 
j=j-1;
} 
a[p]=v;
printf ("array after insertion: \n");
for(i=0;i<n;i++) {
printf("%d\n",a[i]);
}

// DELETION
printf("\n#Deleting element by position:-\n");
n=n-1;
printf("enter position of deleting element: ");
scanf ("%d" ,&p) ;
j=p;
while(¡<=n) {
a[j-1]=a[i]; 
j=j+1;
}
printf("array after deletion:\n");
for(i=0; i‹n; i++) {
printf("%d\n",a[i]);
}

// enter value of deleting element
// DELETION OF VALUE
printf ("\n#Deleting element using value:-\n");
int v2; 
n=n-1;
printf ("enter value of deleting element: "); 
scanf ("%d" , &v2);
for (i=0;i<n; i++) {
if (a[i]==v2) {
int p=i;
for(i=p; i‹n; i++) { 
a[i]=a[i+1];
printf("array after deletion: \n");
for(i=0;i<n; i++) {
printf("%d\n", a [i]);
break;
}
}

// UPDATION
int pp, vv;
printf ("\n#updating an element:-\n");
printf("enter position of an updating element: ");
scanf ("%d" , &pp);
printf ("enter value: "); 
scanf ("%d" ‚&vv);
a[pp-1]=vv;
printf ("array after updation: \n");
for(i=0;i<n; i++) {
printf("d\n",a[i]);
}











