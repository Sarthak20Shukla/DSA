//binarysearch
#include<bits/stdc++.h>

using namespace std;

int search(vector<int> &nums, int target) {
    // Write your code here.
    int low=0,high=nums.size();
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int main(){

    

    return 0;
}
