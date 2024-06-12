//Brust baloons
// memoisation
class Solution {
public:
int f(int i,int j,vector<int>& nums,vector<vector<int>> &dp){
    if(i>j) return 0;
    int mini=INT_MIN;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int ind=i;ind<=j;ind++){
        int cost=nums[i-1]*nums[ind]*nums[j+1]+f(i,ind-1,nums,dp)+f(ind+1,j,nums,dp);
        mini=max(mini,cost);
    }
    return dp[i][j]=mini;
}
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(1, n, nums, dp);
    }
};
//tabulation
class Solution {
public:
int f(int i,int j,vector<int>& nums,vector<vector<int>> &dp){
    if(i>j) return 0;
    int mini=INT_MIN;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int ind=i;ind<=j;ind++){
        int cost=nums[i-1]*nums[ind]*nums[j+1]+f(i,ind-1,nums,dp)+f(ind+1,j,nums,dp);
        mini=max(mini,cost);
    }
    return dp[i][j]=mini;
}
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for(int i=n;i>=1;i--){
        for(int j=1;j<=n;j++){
            if(i>j){continue;}

        int mini=INT_MIN;
            for(int ind=i;ind<=j;ind++){
        int cost=(nums[i-1]*nums[ind]*nums[j+1])+dp[i][ind-1]+dp[ind+1][j];
        mini=max(mini,cost);
    }
     dp[i][j]=mini;
            }
    }
    return  dp[1][n];

    }
};