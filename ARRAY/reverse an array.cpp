//reverse an array
#include<bits/stdc++.h>
using namespace std;
void printarray(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void reverse(int b[],int n) {
    int start=0,end=n-1;
    while(start<=end){swap(b[start],b[end]);
    start++;
    end--;}
}


int main(){
 int arr[6]={1,4,0,5,-2,15};
 int brr[5]={2,6,3,9,4};
 reverse(arr,6);
 reverse(brr,5);
 printarray(arr,6);
 printarray(brr,5); 
    return 0;
}