//first and last element in a sorted array
#include<bits/stdc++.h>
using namespace std;
int firstocc(int arr[],int n,int key){
    int s=0,e=n-1,ans;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
          ans=mid;
          e=mid-1;
        } else if(key >arr[mid]){
           s=mid+1;
        } else if(key<arr[mid]){//left
           e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int lastocc(int arr[],int n,int key){
    int s=0,e=n-1,ans;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==key){
          ans=mid;
          s=mid+1;
        } else if(key >arr[mid]){
           s=mid+1;
        } else if(key<arr[mid]){//left
           e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
int even[10]={1,2,3,3,3,3,3,3,3,5};
cout<<"first occurance of 3 is "<<firstocc(even,10,3)<<endl;
cout<<"last occurance of 3 is "<<lastocc(even,10,3)<<endl;

}