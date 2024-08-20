class Solution {
public:
int solve(int currA,int clipA,int n,vector<vector<int>> &dp){
    if(currA==n) return 0;
    if(currA>n) return 100000;
    if(dp[currA][clipA]!=-1) return dp[currA][clipA];

    int cpp=1+1+solve(currA+currA,currA,n,dp);
    int p=1+solve(currA+clipA,clipA,n,dp);
    return dp[currA][clipA]=min(cpp,p);
}
    int minSteps(int n) {
        if (n == 1) return 0;
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return 1+solve(1,1,n,dp);
        
    }
};