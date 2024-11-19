class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        long long maxi = 0;
        unordered_map<int,int> check;
        for(int i=0;i<k-1;i++)
        {
            sum = sum + nums[i];
            check[nums[i]]++;
        }
        for(int i=k-1;i<n;i++)
        {
            check[nums[i]]++;
            sum = sum + nums[i];
            if(check.size() == k)
            {
                maxi = max(maxi,sum);
            }
            if(check[nums[i-k+1]] == 1)
            {
                check.erase(nums[i-k+1]);
            }
            else
            {
                check[nums[i-k+1]]--;
            }
            sum = sum - nums[i-k+1];
        }
        return maxi;
    }
};