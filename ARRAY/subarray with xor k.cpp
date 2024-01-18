//count subarray with xor k;
#include<bits/stdc++.h>

using namespace std;
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    int n=a.size();int cnt=0;int xr=0;  
    map<int,int>mpp;
    mpp[xr]++;
    for(int i=0;i<n;i++){
        xr=xr^a[i];
        int x=xr^b;
        cnt+=mpp[x];
        mpp[xr]++;
        
    }
    return cnt;
}
int subarraysWithSumKbetter(vector < int > a, int b) {
    // Write your code here
    int n=a.size();int cnt=0;
    for(int i=0;i<n;i++){
        int xr=0;
        for(int j=i;j<n;j++){
            xr=xr^a[j];
            if(xr==b) cnt++;
        }
    }
    return cnt;
}
int subarraysWithSumKbruteforce(vector < int > a, int b) {
    // Write your code here
    int n=a.size();int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int xr=0;
            for(int k=i;k<j;k++){
            xr=xr^a[k];
            if(xr==b) cnt++;
        }
    }
    return cnt;
}
int main(){

    

    return 0;
}
