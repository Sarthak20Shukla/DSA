//ceil and floor of a number
#include<bits/stdc++.h>

using namespace std;

int flr(vector<int> &a, int n, int x){
int high=n-1,low=0;int ans=-1;

while(low<=high){
	int mid=(high+low)/2;
if(a[mid]<=x){
	ans=a[mid];
	low=mid+1;
}
else high=mid-1;
}
return ans;
}
int cel(vector<int> &a, int n, int x){
int high=n-1,low=0;int ans=-1;

while(low<=high){
	int mid=(high+low)/2;
if(a[mid]>=x){
	ans=a[mid];
	high=mid-1;
}
else low=mid+1;
}
return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	return make_pair(flr(a,n,x),cel(a,n,x));
}

int main(){

    

    return 0;
}
