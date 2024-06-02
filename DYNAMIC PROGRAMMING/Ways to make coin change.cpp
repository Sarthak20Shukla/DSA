//Ways to make coin change
//recurrance
class Solution {
public:
    int helper(int ind,int T,vector<int>& coins){
        if(ind==0){
            return (T%coins[0]==0);
        }
        int take=0;
        int nottake=helper(ind-1,T,coins);
        if(coins[ind]<=T) take=helper(ind,T-coins[ind],coins);

        return take+nottake;

    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return helper(n-1,amount,coins);
    }
};
//memoization
class Solution {
public:
    int helper(int ind,int T,vector<int>& coins,vector<vector<int>> &dp){
        if(ind==0){
            return (T%coins[0]==0);
        }
        if(dp[ind][T]!=-1) return dp[ind][T];
        int take=0;
        int nottake=helper(ind-1,T,coins,dp);
        if(coins[ind]<=T) take=helper(ind,T-coins[ind],coins,dp);

        return dp[ind][T]=take+nottake;

    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return helper(n-1,amount,coins,dp);
    }
};
//tabulation

int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int target=0;target<=amount;target++){
            dp[0][target]=(target%coins[0]==0);
        }
        for(int ind=1;ind<n;ind++){
            for(int T=0;T<=amount;T++){
                    int take=0;
                    int nottake=dp[ind-1][T];
                    if(coins[ind]<=T) take=dp[ind][T-coins[ind]];

                 dp[ind][T]=take+nottake;
            }
        }
        return dp[n-1][amount];
    }
};
//search space
class Solution {
public:
    int helper(int ind,int T,vector<int>& coins,vector<vector<int>> &dp){
        if(ind==0){
            return (T%coins[0]==0);
        }
        if(dp[ind][T]!=-1) return dp[ind][T];
        int take=0;
        int nottake=helper(ind-1,T,coins,dp);
        if(coins[ind]<=T) take=helper(ind,T-coins[ind],coins,dp);

        return dp[ind][T]=take+nottake;

    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        vector<int> prev(amount+1,0),curr(amount+1,0);
        for(int target=0;target<=amount;target++){
            prev[target]=(target%coins[0]==0);
        }
        for(int ind=1;ind<n;ind++){
            for(int T=0;T<=amount;T++){
                    int take=0;
                    int nottake=prev[T];
                    if(coins[ind]<=T) take=curr[T-coins[ind]];

                 curr[T]=take+nottake;
            }
            prev=curr;
        }
        return prev[amount];
    }
};
