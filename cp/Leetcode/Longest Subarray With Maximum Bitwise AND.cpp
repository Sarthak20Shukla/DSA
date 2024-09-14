class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int x=0;
        for(int i=0;i<nums.size();i++){
            
                x=max(nums[i],x);
            
        }
        int len=1;
        int curr=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==x && nums[i-1]==nums[i]){
                curr++;
                len=max(len,curr);
            } else curr=1;
        }
        return len;
    }
};