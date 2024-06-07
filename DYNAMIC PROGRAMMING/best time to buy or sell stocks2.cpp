//best time to buy or sell stocks2
//memoization
class Solution {
public:
int f(int ind,int buy,vector<int>& prices,vector<vector<int>> &dp){
    int n=prices.size();
    if(ind==n) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    int profit=0;
    if(buy){
        profit=max(prices[ind]+f(ind+1,0,prices,dp),0+f(ind+1,1,prices,dp));
    } else {
        profit=max(-prices[ind]+f(ind+1,1,prices,dp),0+f(ind+1,0,prices,dp));

    }
    return dp[ind][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return f(0,0,prices,dp);

    }
};
//tabulation
class Solution {
public:
int f(int ind,int buy,vector<int>& prices,vector<vector<int>> &dp){
    int n=prices.size();
    if(ind==n) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];
    int profit=0;
    if(buy){
        profit=max(prices[ind]+f(ind+1,0,prices,dp),0+f(ind+1,1,prices,dp));
    } else {
        profit=max(-prices[ind]+f(ind+1,1,prices,dp),0+f(ind+1,0,prices,dp));

    }
    return dp[ind][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();                int profit;

        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
    if(buy==1){
    profit=max(prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
    } if(buy==0) {
        profit=max(-prices[ind]+dp[ind+1][1],0+dp[ind+1][0]);

    }
     dp[ind][buy]=profit;
            }
        }

        return dp[0][0];

    }
};
//spaceoptimisation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();                int profit;

        vector<vector<int>> dp(n+1, vector<int>(2, 0));
         vector<int>ahead(2, 0);
          vector<int>curr(2, 0);
        ahead[0]=ahead[1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
    if(buy==1){
    profit=max(prices[ind]+ahead[0],0+ahead[1]);
    } if(buy==0) {
        profit=max(-prices[ind]+ahead[1],0+ahead[0]);

    }
     curr[buy]=profit;
            }
            ahead=curr;
        }

        return ahead[0];

    }
};

