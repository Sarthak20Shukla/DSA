//rowWithMax1s
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
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    //    Write your code here.
    int max_index=-1,index=-1;
    for(int i=0;i<n;i++){
        int no_of_ones=m-lowerBound(matrix[i],m,1);
        if(no_of_ones>max_index){
            max_index=no_of_ones;
            index=i;
        }
    }
    return index;
}

int main(){

    

    return 0;
}
