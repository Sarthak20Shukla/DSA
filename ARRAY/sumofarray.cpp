#include<bits/stdc++.h>
using namespace std;
int summ(int arr[],int n){
  int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int main(){
 int size;
 cin>>size;
 int a[size];
 for(int i=0;i<size;i++)
{
    cin>>a[i];
}
cout<<"the sum of array is "<<summ(a,size)<<endl;;
    return 0;
    
    }