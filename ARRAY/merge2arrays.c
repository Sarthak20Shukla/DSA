#include<stdio.h>
void merge2arrays(int a[],int b[],int c[],int n1,int n2){
int i=0,j=0,k=0;
while(i<n1&&j<n2){
    if(a[i]<b[j]){
        c[k++]=a[i++];
    } else {
        c[k++]=b[j++];
    }
}
while(i<n1){
    c[k++]=a[i++];
} while(j<n2){
    c[k++]=b[j++];
}

}
void printarray(int c[],int n3){
    printf("array after merging\n");
    for(int i=0;i<n3;i++){
        printf("%d\t",c[i]);
    }
}
int main(){
int n1,n2,n3,a[100],b[100],c[100];int i;
printf("enter 1 array\n");
scanf("%d",&n1);
for(i=0;i<n1;i++){
    scanf("%d",&a[i]);
}
printf("enter 2 array\n");
scanf("%d",&n2);
for(i=0;i<n2;i++){
    scanf("%d",&b[i]);
}

merge2arrays(a,b,c,n1,n2);
n3=n1+n2;
printarray(c,n3);
return 0;
}