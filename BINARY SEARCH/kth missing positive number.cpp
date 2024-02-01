//kth missing positive number
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& vec, int k) {
        int n=vec.size(); 
         int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing=vec[mid]-(mid+1);
        if(missing<k) low=mid+1;
        else high=mid-1;
    }
    return (high+1+k);
        
    }
};

int main(){

    

    return 0;
}