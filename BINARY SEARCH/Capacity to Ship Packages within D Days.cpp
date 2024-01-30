//Capacity to Ship Packages within D Days
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
int daysfunction(vector<int>& weights, int capacity){
    int days=1,load=0;
    for(int i=0;i<weights.size();i++){
        if(load+weights[i]>capacity){
            days++;
            load=weights[i];
        } else {
            load+=weights[i];
        }
    }
    return days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int no_of_days=daysfunction(weights,mid);
            if(no_of_days<=days) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};

int main(){

    

    return 0;
}
