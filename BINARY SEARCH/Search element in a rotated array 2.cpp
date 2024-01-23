//Search element in a rotated array 2
#include<bits/stdc++.h>

using namespace std;

bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
    // Write your code here.
    int n=A.size();
    int low=0;int high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(A[mid]==key) return true;
        if(A[low]==A[mid] && A[mid]==A[high]){
            high--;
            low++;
            continue;
        }
        if(A[low]<=A[mid]){
            if(A[low]<=key && key<=A[mid]){
                high=mid-1;
            } else {
                low=mid+1;
            }
        } else{
            if(A[mid]<=key && key<=A[high]){
                low=mid+1;
            } else {
                high=mid-1;
            }

        }
    }
    return false;
}


int main(){

    

    return 0;
}
