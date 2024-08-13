class Solution {
public:
   
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> d;
        combineSum(ans,d,candidates,0,target);
        return ans;
    }

     void combineSum(vector<vector<int>> &ans,vector<int> &d,vector<int> &candidates,int ind,int target){
        if(target<0) return;
        if(target==0){
            ans.push_back(d);
            return;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            d.push_back(candidates[i]);
            combineSum(ans,d,candidates,i+1,target-candidates[i]);
            d.pop_back();
        }

    }
};