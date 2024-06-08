//Longest  Increasing Subsequence
//Recursion
class Solution {
public:
    int f(int ind,int prev_ind,vector<int>& nums){
        int n=nums.size();
        if(ind==n) return 0;

        int len=0+f(ind+1,prev_ind,nums);
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            len=max(len,1+f(ind+1,ind,nums));
        }
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        return f(0,-1,nums);
    }
};
//memoisation
class Solution {
public:
    int f(int ind,int prev_ind,vector<int>& nums,vector<vector<int>> &dp){
        int n=nums.size();
        if(ind==n) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];

        int len=0+f(ind+1,prev_ind,nums,dp);
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            len=max(len,1+f(ind+1,ind,nums,dp));
        }
        return dp[ind][prev_ind+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }
};
//tabulation
int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,0));
            int len=0+dp[ind+1][prev_ind];
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            len=max(len,1+dp[ind+1][ind]);
        }
         dp[ind][prev_ind+1]=len;
        return dp[0][0];
    }