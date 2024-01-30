//Aggressive Cows

#include<bits/stdc++.h>

using namespace std;

bool placeCows(vector<int> &stalls,int d, int k){
    int last=stalls[0],cowscnt=1;int n=stalls.size();
    for(int i=1;i<n;i++){
        if(stalls[i]-last>=d){
            cowscnt++;
            last=stalls[i];
        }
        if(cowscnt>=k) return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.

    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    int low=1,high=stalls[n-1]-stalls[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(placeCows(stalls,mid,k)==true){
            low=mid+1;
        } else high=mid-1;
    }
    return high;
}

int main(){

    

    return 0;
}
