//implement lower bound
#include<bits/stdc++.h>

using namespace std;
int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int low=0,high=n-1;
	int ans=n;
	while(low<=high){
		int mid=(low+high)/2;
		if(x<=arr[mid]){
			ans=mid;
			high=mid-1;
		} else {
			low=mid+1;
		}
	}
	return ans;
}

int main(){

    

    return 0;
}
