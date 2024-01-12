//largest element of an array using pointer
#include<stdio.h>

int main(){
 int a[100],n,i,large;
 printf("enter a number\n");
 scanf("%d",&n);
 printf("enter an array\n");
 for(i=0;i<n;i++){
    scanf("%d",&(*(a+i)));
 }
 large=*(a+0);
 for(i=0;i<n;i++){
  if(*(a+i)>large){
    large=*(a+i);
  }  
 }
 printf("the largest element is %d",large);


return 0;
}