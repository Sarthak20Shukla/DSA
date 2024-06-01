//target sum
//tabulation
class Solution {
public:
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));
	if(arr[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    
    if(arr[0]!=0 && arr[0]<=k) dp[0][arr[0]] = 1; 

    for(int i = 1; i < n; i++){

        for(int sum = 0; sum <= k; sum ++){

            int not_take = dp[i-1][sum];

            int take = 0;

            if(arr[i] <= sum) take = dp[i-1][sum-arr[i]];

            dp[i][sum] = (take + not_take);

        }

    }

    return dp[n-1][k];
	
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totsum=0;
    for(int i=0;i<n;i++){
        totsum+=arr[i];
    }
    if(totsum-d<0 || (totsum-d)%2!=0){
        return 0;
    }
    return findWays(arr,(totsum-d)/2);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return countPartitions(n,target,nums);
    }
};