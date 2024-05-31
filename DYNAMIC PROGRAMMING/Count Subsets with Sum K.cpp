//Count Subsets with Sum K
//recurranx=ce
int helper(int ind,int sum,vector<int>& arr){
	if(sum==0) return 1;
	if(ind==0) return (arr[ind]==sum);

	int notpick=helper(ind-1,sum,arr);
	int pick=0;
	if(arr[ind]<=sum) pick=helper(ind-1,sum-arr[ind],arr);

	return pick+notpick;
}
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n=arr.size();
	return helper(n-1,k,arr);
}

//memoization
int helper(int ind,int sum,vector<int>& arr,vector<vector<int>> dp){
	if(sum==0) return 1;
	if(ind==0) return (arr[ind]==sum);
	if(dp[ind][sum]!=-1) return dp[ind][sum];
	int notpick=helper(ind-1,sum,arr,dp);
	int pick=0;
	if(arr[ind]<=sum) pick=helper(ind-1,sum-arr[ind],arr,dp);

	return dp[ind][sum]=pick+notpick;
}
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n=arr.size();
	vector<vector<int>> dp(n, vector<int>(k + 1, -1));
	return helper(n-1,k,arr,dp);
}

//tabulation
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n=arr.size();
	sort(arr.begin(), arr.end());

    vector<vector<int>> dp(n, vector<int> (k+1, 0));

    sort(arr.begin(), arr.end());
	    for(int i = 0; i < n; i++) dp[i][0] = 1;

    if(arr[0] <= k) dp[0][arr[0]] = 1;

    for(int i = 1; i < n; i++){

        for(int sum = 1; sum <= k; sum ++){

            int not_take = dp[i-1][sum]%mod;

            int take = 0;

            if(arr[i] <= sum) take = dp[i-1][sum-arr[i]]%mod;

            dp[i][sum] = (take + not_take)%mod;

        }

    }

    //return dp[n-1][k];
	 int count = 0;

    for(int i  = 0; i < n; i++){

        if(arr[i] != 0) break;

        count++;

    }

    int ans1 = 1;

    for(int i = 0; i < count; i++){

        ans1 *= 2;

        ans1 %= mod;

    }

    return ans1*dp[n-1][k];
}
