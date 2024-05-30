// Subset Sum Equal To K
//memoization
#include <bits/stdc++.h> 
bool helper(int ind,int target, vector<int> &arr,vector<vector<int>> &dp){
    if(target==0) return true;
    if(ind==0) return (arr[0]==target);
    
      if(ind < 0){
        return false;
    }

    if(target < 0){
        return false;
    }
    if(dp[ind][target]!=-1) return dp[ind][target];

    bool take=false;
    bool nottake=helper(ind-1,target,arr,dp);
    if(arr[ind]<=target) take=helper(ind-1,target-arr[ind],arr,dp);

    return dp[ind][target]= nottake | take;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return helper(n-1,k,arr,dp);
}
//tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>>dp(n,vector<bool>(k+1,false));
for(int i=0;i<n;i++){
    dp[i][0]=true;
}
if(arr[0]<=k)
dp[0][arr[0]]=true;
for(int ind=1;ind<n;ind++){
    for(int target=1;target<=k;target++){
        bool take=false;
    bool nottake=dp[ind-1][target];
    if(arr[ind]<=target) take=dp[ind-1][target-arr[ind]];

     dp[ind][target]= nottake | take;

    }
}
return dp[n-1][k];

}
//space optimisation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
       vector<bool> prev(k + 1, false);
       prev[0]=true;
// vector<vector<bool>>dp(n,vector<bool>(k+1,false));

if(arr[0]<=k) prev[arr[0]]=true;
for(int ind=1;ind<n;ind++){
        vector<bool> curr(k + 1, false);
curr[0]=true;
    for(int target=1;target<=k;target++){
        bool take=false;
    bool nottake=prev[target];
    if(arr[ind]<=target) take=prev[target-arr[ind]];

     curr[target]= nottake | take;

    }
    prev = curr;
}
return prev[k];

}