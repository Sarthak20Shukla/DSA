//best time to buy or sell stocks3
//recursion and memoisation
class Solution {
public:
    int f(int ind,int buy,int cap,vector<int> &prices,vector<vector<vector<int>>> &dp) {
        if(ind==prices.size() || cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy==1) {
            return dp[ind][buy][cap]=max(-prices[ind]+f(ind+1,0,cap,prices,dp),0+f(ind+1,1,cap,prices,dp));
        }else {
             return dp[ind][buy][cap]=max(prices[ind]+f(ind+1,1,cap-1,prices,dp),0+f(ind+1,0,cap,prices,dp));

        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,dp);
    }
};
//tabulation
class Solution {
public:
    int f(int ind,int buy,int cap,vector<int> &prices,vector<vector<vector<int>>> &dp) {
        if(ind==prices.size() || cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy==1) {
            return dp[ind][buy][cap]=max(-prices[ind]+f(ind+1,0,cap,prices,dp),0+f(ind+1,1,cap,prices,dp));
        }else {
             return dp[ind][buy][cap]=max(prices[ind]+f(ind+1,1,cap-1,prices,dp),0+f(ind+1,0,cap,prices,dp));

        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
       /* for(int ind=0;ind<=0;ind++){
            for(int buy=0;buy<=1;buy++){
                dp[ind][buy][0]=0;
            }
        }
        
         for(int buy=0;buy<=1;buy++){
            for(int cap=0;cap<=2;cap++){
                dp[n-1][buy][cap]=0;
            }
        }*/

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
             if(buy==1) {
             dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                }else {
              dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);

        }


            }
            }
            }
            return dp[0][1][2];
    }
};
//space optimisation
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>ahead(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));

       /* for(int ind=0;ind<=0;ind++){
            for(int buy=0;buy<=1;buy++){
                dp[ind][buy][0]=0;
            }
        }
        
         for(int buy=0;buy<=1;buy++){
            for(int cap=0;cap<=2;cap++){
                dp[n-1][buy][cap]=0;
            }
        }*/

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
             if(buy==1) {
             curr[buy][cap]=max(-prices[ind]+ahead[0][cap],0+ahead[1][cap]);
                }else {
              curr[buy][cap]=max(prices[ind]+ahead[1][cap-1],0+ahead[0][cap]);

        }


            }
            }
            ahead=curr;
            }
            return ahead[1][2];
    }
};
