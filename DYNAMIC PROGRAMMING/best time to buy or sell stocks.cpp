//best time to buy or sell stocks
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();int cost;
        int mini=prices[0];
        for(int i=1;i<n;i++){
             cost=prices[i]-mini;
            profit=max(profit,cost);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};