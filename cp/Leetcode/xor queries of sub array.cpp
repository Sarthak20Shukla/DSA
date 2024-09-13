class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
         
            int s=arr[queries[i][0]];
            for(int j=queries[i][0];j<queries[i][1];j++){
                s ^= arr[j+1];
            }
            ans.push_back(s);

        }
        return ans;
    }
};