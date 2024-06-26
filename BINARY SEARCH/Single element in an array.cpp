//Single element in an array
#include<bits/stdc++.h>

using namespace std;

int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int n=arr.size();
	int low=1,high=n-2;
	if(n==1) return arr[0];
	if(arr[0]!=arr[1]) return arr[0];
	if(arr[n-1]!=arr[n-2]) return arr[n-1];
	while(low<=high){
		int mid=(high+low)/2;
		if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
			return arr[mid];
		}
		if((mid%2==1 && arr[mid-1]==arr[mid])||(mid%2==0 && arr[mid]==arr[mid+1])){
			low=mid+1;
		} else{
			high=mid-1;
		}
	}
	return -1;

}

int main(){

    

    return 0;
}
