//find first and last position of an element in an array using bs

#include<bits/stdc++.h>

using namespace std;
int lowerbound(vector<int>& arr, int n, int k){
    int low=0,high=n-1,ans=n;
    while(low<=high){
      int mid=(high+low)/2;
        if(arr[mid]>=k){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}
int upperbound(vector<int>& arr, int n, int k){
    int low=0,high=n-1,ans=n;
    while(low<=high){
       int mid=(high+low)/2;
        if(arr[mid]>k){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int lb=lowerbound(arr,n,k);
    if(lb==n||arr[lb]!=k) return {-1,-1};
    return {lb,upperbound(arr,n,k)-1};

}


int main(){

    

    return 0;
}
