//Minimum days to make M bouquets
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
bool possible(vector<int> arr,int day,int k, int m){
	int cnt=0,noofb=0;
	int n=arr.size();
	for(int i=0;i<n;i++){
		if(arr[i]<=day){
			cnt++;

		} else {
			noofb+=(cnt/k);
			cnt=0;
		}
	}
	noofb+=(cnt/k);
	if(noofb>=m) return true;
	else return false;

}
    int minDays(vector<int>& arr, int m, int k) {
        	int n=arr.size();
	int mini=INT_MAX,maxi=INT_MIN;
	for(int i=0;i<n;i++){
		maxi=max(maxi,arr[i]);
		mini=min(mini,arr[i]);
	}
	int low=mini,high=maxi;
    long long val=k*1ll*m*1ll;
	if(n<val) return -1;
	while(low<=high){
		int mid=(low+high)/2;
		if(possible(arr,mid,k,m)== true){
			high=mid-1;
			
		} else {
			low=mid+1;
		}

	}
	return low;
    }
};

int main(){

    

    return 0;
}
