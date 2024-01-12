#include<bits/stdc++.h>

using namespace std;

int bestTimeToBuyAndSellStock(vector<int>&prices) {
    // Write your code here.
    int profit=0,mini=prices[0];int cost;
    for(int i=1;i<prices.size();i++){
        cost=prices[i]-mini;
        profit=max(cost,profit);
        mini=min(mini,prices[i]);
        
    }
    return profit;
}


int main(){

    vector<int> prices={1,2,3,4,5};
    cout<<bestTimeToBuyAndSellStock(prices);

    return 0;
}
