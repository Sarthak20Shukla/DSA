//minSubsetSumDifference
int minSubsetSumDifference(vector<int>& nums, int n)
{
	// Write your code here.
	int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int k=sum;
        vector<vector<bool>> dp(n,vector<bool>(k+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=sum) dp[0][sum]=true;
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=k;target++){
                bool take=false;
                bool nottake=dp[ind-1][target];
                if(nums[ind]<=target){
                    take=dp[ind-1][target-nums[ind]];
                }
                dp[ind][target]=take || nottake;
            }
        }
        int mini=1e9;
        for(int i=0;i<sum;i++){
            if(dp[n-1][i]==true){
            int s1=i;
            int s2=sum-i;
            mini=min(mini,abs(s1-s2));
        }}
        return mini;
}
