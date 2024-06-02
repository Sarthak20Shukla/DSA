//unbounded knapsack
//Recursion
int f(int ind, int W, vector<int> &profit, vector<int> &weight){
    if(ind==0){
        return ((int)(W/weight[0]))*profit[0];
    }
    int nottake=0+f(ind-1,W,profit,weight);
    int take=0;
    if(weight[ind]<=W) take=profit[ind]+f(ind,W-weight[ind],profit,weight);
    return max(take,nottake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    return f(n-1,w,profit,weight);
}
//memoisation
int f(int ind, int W, vector<int> &profit, vector<int> &weight,vector<vector<int>> &dp){
    if(ind==0){
        return ((int)(W/weight[0]))*profit[0];
    }
    if(dp[ind][W]!=-1) return dp[ind][W];
    int nottake=0+f(ind-1,W,profit,weight,dp);
    int take=0;
    if(weight[ind]<=W) take=profit[ind]+f(ind,W-weight[ind],profit,weight,dp);
    return dp[ind][W]=max(take,nottake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return f(n-1,w,profit,weight,dp);
}
//tabulation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    for(int W=0;W<w;W++){
        dp[0][w]=((int)(w/weight[0]))*profit[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=w;W++){
            int nottake=0+dp[ind-1][W];
    int take=0;
    if(weight[ind]<=W) take=profit[ind]+dp[ind][W-weight[ind]];
     dp[ind][W]=max(take,nottake);
        }
    }
    return dp[n-1][w];
}
//space optimisation
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<int>prev(w+1,0);
     vector<int>curr(w+1,0);
    for(int W=0;W<w;W++){
        prev[w]=((int)(w/weight[0]))*profit[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=w;W++){
            int nottake=0+prev[W];
    int take=0;
    if(weight[ind]<=W) take=profit[ind]+curr[W-weight[ind]];
     curr[W]=max(take,nottake);
        }
        prev=curr;
    }
    return prev[w];
}
//single array SO
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<int>prev(w+1,0);
    for(int W=0;W<w;W++){
        prev[w]=((int)(w/weight[0]))*profit[0];
    }
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=w;W++){
            int nottake=0+prev[W];
    int take=0;
    if(weight[ind]<=W) take=profit[ind]+prev[W-weight[ind]];
     prev[W]=max(take,nottake);
        }
    }
    return prev[w];
}
