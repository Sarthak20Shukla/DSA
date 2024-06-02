//Rod Cutting Problem
//recursion
int f(int ind,int N,vector<int> &price){
	if(ind==0){
		return N*price[0];
	}

	int take=INT_MIN;
	int nottake=0+f(ind-1,N,price);
	int rod=ind+1;
	if(rod<=N){
		take=price[ind]+f(ind,N-rod,price);
	}
	return max(take,nottake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	return f(n-1,n,price);
}

//memoisation
int f(int ind,int N,vector<int> &price,vector<vector<int>> &dp){
	if(ind==0){
		return N*price[0];
	}
    if(dp[ind][N]!=-1) return dp[ind][W];

	int take=INT_MIN;
	int nottake=0+f(ind-1,N,price,dp);
	int rod=ind+1;
	if(rod<=N){
		take=price[ind]+f(ind,N-rod,price,dp);
	}
	return dp[ind][N]= max(take,nottake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n,vector<int>(n+1));
	return f(n-1,n,price,dp);
}

//tabulation
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<vector<int>> dp(n,vector<int>(n+1));
	for(int N=0;N<=n;N++){
		dp[0][N]=N*price[0];
	}
	for(int ind=1;ind<n;ind++){
		for(int N=0;N<=n;N++){
			int take=INT_MIN;
	int nottake=0+dp[ind-1][N];
	int rod=ind+1;
	if(rod<=N){
		take=price[ind]+dp[ind][N-rod];
	}
	dp[ind][N]= max(take,nottake);
		}
	}
	return dp[n-1][n];

}
//space optimisation

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int>prev(n+1);
		vector<int>curr(n+1);

	for(int N=0;N<=n;N++){
		prev[N]=N*price[0];
	}
	for(int ind=1;ind<n;ind++){
		for(int N=0;N<=n;N++){
			int take=INT_MIN;
	int nottake=0+prev[N];
	int rod=ind+1;
	if(rod<=N){
		take=price[ind]+curr[N-rod];
	}
	curr[N]= max(take,nottake);
		}
		prev=curr;
	}
	return prev[n];

}
//1d array SO

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int>prev(n+1);

	for(int N=0;N<=n;N++){
		prev[N]=N*price[0];
	}
	for(int ind=1;ind<n;ind++){
		for(int N=0;N<=n;N++){
			int take=INT_MIN;
	int nottake=0+prev[N];
	int rod=ind+1;
	if(rod<=N){
		take=price[ind]+prev[N-rod];
	}
	prev[N]= max(take,nottake);
		}
	
	}
	return prev[n];

}


