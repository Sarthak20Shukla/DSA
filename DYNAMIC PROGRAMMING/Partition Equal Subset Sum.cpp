//Partition Equal Subset Sum
//space optimisation
class Solution {
public:
    bool helper(int n,int k,vector<int>& nums){
        vector<bool> prev(k+1,false);
        prev[0]=true;
        if(nums[0]<=k)  prev[nums[0]]=true;
        for(int ind=1;ind<n;ind++){
            vector<bool> curr(k+1,false);
            curr[0]=true;
            for(int target=1;target<=k;target++){
                bool take=false;
                bool nottake=prev[target];
                if(nums[ind]<=target) take=prev[target-nums[ind]];
                curr[target]=take|nottake;
            }
            prev=curr;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;int target;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        else    target=sum/2;
        if(n==1){
            return false;
        }

        return helper(n,target,nums);
    }
};