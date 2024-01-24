//no of times the array is rotated
#include<bits/stdc++.h>

using namespace std;
#include<bits/stdc++.h>

int findKRotation(vector<int> &arr){
    // Write your code here.    
    	int n=arr.size();
	int high=n-1;int low=0;int ans=INT_MAX;int index=-1;
	while(low<=high){
		int mid=(high+low)/2;
		if(arr[low]<=arr[high]){
			if(arr[low]<ans){
                ans=arr[low];
                index=low;
            }
			break;
		}
		if(arr[low]<=arr[mid]){
			if(arr[low]<ans){
                ans=arr[low];
                index=low;
            }
			low=mid+1;
		}else{
			if(arr[mid]<ans){
                ans=arr[mid];
                index=mid;
            }
			high=mid-1;
		}
	}
	return index;
}

int main(){

    

    return 0;
}
