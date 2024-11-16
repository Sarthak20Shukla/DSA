class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
         int n=nums.size();
        vector<int> ans(n-k+1);

        for(int i=0;i<n-k+1;i++){
            bool isInOrder=true;
            for(int j=i;j<i+k-1;j++){
                if(nums[j+1] != nums[j]+1) {
                    isInOrder=false;
                    break;
                }
            }
                if(isInOrder){
                    int x=nums[i+k-1];
                    ans[i]=x;
                } else {
                    ans[i]=-1;
                }
            
        }
        return ans;
    }
};