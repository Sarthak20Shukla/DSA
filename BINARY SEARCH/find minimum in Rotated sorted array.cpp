//find minimum in Rotated sorted array
#include<bits/stdc++.h>

using namespace std;

int findMin(vector<int>& arr)
{
	// Write your code here.
	int n=arr.size();
	int high=n-1;int low=0;int ans=INT_MAX;
	while(low<=high){
		int mid=(high+low)/2;
		if(arr[low]<=arr[high]){
			ans=min(ans,arr[low]);
			break;
		}
		if(arr[low]<=arr[mid]){
			ans=min(ans,arr[low]);
			low=mid+1;
		}else{
			ans=min(ans,arr[mid]);
			high=mid-1;
		}
	}
	return ans;
}

int main(){

    

    return 0;
}
