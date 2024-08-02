#include<bits/stdc++.h>

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt1=0;
        int n=nums.size();
        for(int i=0;i<n;i++) if(nums[i]==1) cnt1++;
        vector<int> temp;
        for(int i=0;i<2*n;i++){
            temp.push_back(nums[i%n]);
        }
        if(cnt1==0) return 0;
        int ws=cnt1;
        int cnt0=0;
        for(int i=0;i<ws;i++){
            if(temp[i]==0) cnt0++;
        }
        int minCnt0=cnt0;
        for(int i=ws;i<temp.size();i++){
            if(temp[i]==0) cnt0++;
            if (temp[i - cnt1] == 0) cnt0--;
            minCnt0=min(minCnt0,cnt0);
        }
        return minCnt0;
        

    }
};