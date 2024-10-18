class Solution {
public:
int countsubsets(int i,int curror,int maxor,vector<int>& nums){
    if(i==nums.size()){
        if(curror==maxor) return 1;
        return 0;
    }
    int take=countsubsets(i+1,curror|nums[i],maxor,nums);
    int nottake=countsubsets(i+1,curror,maxor,nums);
    return take+nottake;
}
    int countMaxOrSubsets(vector<int>& nums) {
        int maxor=0;
        for(int &it:nums){
            maxor|=it;
        }
        int curror=0;
        return countsubsets(0,curror,maxor,nums);
    }
};