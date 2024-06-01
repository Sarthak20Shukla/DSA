//minimum coins
// recursion
class Solution {
public:
    int f(int ind,int target,vector<int>& coins ){
        if(ind==0){
            if(target%coins[ind]==0) return target/coins[ind];
            else return 1e9;
        }
        
        int nottake=0+f(ind-1,target,coins);
        int take=INT_MAX;
        if(coins[ind]<=target) take=1+f(ind,target-coins[ind],coins);

        return (take,nottake);
    }
    int coinChange(vector<int>& coins, int sum) {
        int n=coins.size();
        int a=f(n-1,sum,coins);
        if(a>=1e9) return-1;
        else return a;
    }
};
//memoization
class Solution {
public:
    int f(int ind,int target,vector<int>& coins ,vector<vector<int>> &dp){
        if(ind==0){
            if(target%coins[ind]==0) return target/coins[ind];
            else return 1e9;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nottake=0+f(ind-1,target,coins,dp);
        int take=INT_MAX;
        if(coins[ind]<=target) take=1+f(ind,target-coins[ind],coins,dp);

        return dp[ind][target]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int sum) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        int a=f(n-1,sum,coins,dp);
        if(a>=1e9) return-1;
        else return a;
    }
};
//tabulation
 int coinChange(vector<int>& coins, int sum) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        for(int target=0;target<=sum;target++){
            if(target%coins[0]==0)  dp[0][target]=target/coins[0];
            else dp[0][target]=1e9;
        }
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=sum;target++){
                int notTake = 0+dp[ind-1][target];
                int take=INT_MAX;
                if(coins[ind]<=target){
                    take=1+dp[ind][target-coins[ind]];
                }
                dp[ind][target]=min(take,notTake);
            }
        }
        if(dp[n-1][sum]>=1e9){return -1;}
        else return dp[n-1][sum];
    }
    //space optimisation
    int n=coins.size();
        vector<int> prev(sum+1,-1),curr(sum+1,-1);
        for(int target=0;target<=sum;target++){
            if(target%coins[0]==0)  prev[target]=target/coins[0];
            else prev[target]=1e9;
        }
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=sum;target++){
                int notTake = 0+prev[target];
                int take=INT_MAX;
                if(coins[ind]<=target){
                    take=1+curr[target-coins[ind]];
                }
                curr[target]=min(take,notTake);
            }prev=curr;
        }
        if(prev[sum]>=1e9){return -1;}
        else return prev[sum];