//01 knapsack
//reccurance
#include <bits/stdc++.h> 
int helper(int ind,int wt,vector<int> &value,vector<int> &weight){
	if(ind==0){
		if(weight[0]<=wt) return value[0];
		else return 0;
	}
	int nottake=0+helper(ind-1,  wt, value, weight);
	int take=INT_MIN;
	if(weight[ind]<=wt) take=value[ind]+helper(ind-1,  wt-weight[ind], value, weight);

	return max(take,nottake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	return helper(n-1,maxWeight,value,weight);
}
//memeoization
#include <bits/stdc++.h> 
int helper(int ind,int wt,vector<int> &value,vector<int> &weight,vector<vector<int>>&dp){
	if(ind==0){
		if(weight[0]<=wt) return value[0];
		else return 0;
	}
	if(dp[ind][wt]!=-1) return dp[ind][wt];
	int nottake=0+helper(ind-1,  wt, value, weight,dp);
	int take=INT_MIN;
	if(weight[ind]<=wt) take=value[ind]+helper(ind-1,  wt-weight[ind], value, weight,dp);

	return dp[ind][wt]=max(take,nottake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return helper(n-1,maxWeight,value,weight,dp);
}
//tabulation
#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
	for(int i=weight[0];i<=maxWeight;i++){
		dp[0][i]=value[0];

	}
	for(int ind=1;ind<n;ind++){
		for(int wt=0;wt<=maxWeight;wt++){
			int nottake=0+dp[ind-1][wt];
	int take=INT_MIN;
	if(weight[ind]<=wt) take=value[ind]+dp[ind-1][wt-weight[ind]];

	 dp[ind][wt]=max(take,nottake);
		}
	}
	return dp[n-1][maxWeight];
}
//space optimisation
#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<int>prev(maxWeight+1,0),curr(maxWeight+1,0);
	for(int i=weight[0];i<=maxWeight;i++){
		prev[i]=value[0];

	}
	for(int ind=1;ind<n;ind++){
		for(int wt=0;wt<=maxWeight;wt++){
			int nottake=0+prev[wt];
	int take=INT_MIN;
	if(weight[ind]<=wt) take=value[ind]+prev[wt-weight[ind]];

	 curr[wt]=max(take,nottake);
		}
		prev=curr;
	}
	return prev[maxWeight];
}

//single array space optimisation


#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<int>prev(maxWeight+1,0);
	for(int i=weight[0];i<=maxWeight;i++){
		prev[i]=value[0];

	}
	for(int ind=1;ind<n;ind++){
		for(int wt=maxWeight;wt>=0;wt--){
			int nottake=0+prev[wt];
	int take=INT_MIN;
	if(weight[ind]<=wt) take=value[ind]+prev[wt-weight[ind]];
		prev[wt]=max(take,nottake);

		}
	}
	return prev[maxWeight];
}