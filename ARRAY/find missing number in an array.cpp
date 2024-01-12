// find missing number in an array
#include<bits/stdc++.h>

using namespace std;
int missingburteforce(int arr[],int n){
int hash[n+1]={0};int missingelement;
for(int i=0;i<n;i++){
    hash[arr[i]]=1;
}
for(int i=1;i<n;i++){
    if(hash[i]==0){
        missingelement=i;
    }
}
return missingelement;
}
int missingoptimal2(int arr[],int n){
int xor1=0,xor2=0;
for(int i=0;i<n-1;i++){
    xor1=xor1^arr[i];
    xor2=xor2^(i+1);
}
xor1=xor1^n;
return {xor1^xor2};
}
int missingoptimal1(int arr[],int n){
int sum1=0,sum2=0;
for(int i=0;i<n;i++){
    sum1+=(i+1);sum2+=arr[i];
}
return {sum1-sum2};
}
int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Missing Element is :- "<<missingoptimal1(arr,n)<<endl;
    return 0;
}
