//4 sum
#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> fourSumOptimal(vector<int>& nums, int target) {
    // Write your code here
  int n=nums.size();
    int j;
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++) {
     if(i>0 && nums[i]==nums[i-1]) continue;
     for(j=i+1;j<n;j++){
         if(j > i+1 && nums[j]==nums[j-1]) continue;
     
     int k=j+1;
     int l=n-1;
     while(k<l){
                long long sum=nums[i]+nums[j]+nums[k]+nums[l];
                if(sum==target) {
                  vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                  ans.push_back(temp);
                  k++;
                  l--;
                  while (k < l && nums[k] == nums[k - 1])
                    k++;
                  while (k < l && nums[l] == nums[l + 1])
                    l++;
                } else if (sum < target)
                  k++;
                else
                  l--;
     }
     }
    }
    return ans;
}


vector<vector<int>> fourSumBetter(vector<int>& nums, int target) {
    // Write your code here
    int n=nums.size();
    set<vector<int>> st;
    for(int i=0;i<n;i++) {
        set<int> hashset;
        for(int j=i+1;j<n;j++){
            
            for(int k=j+1;k<n;k++){
                int sum=nums[i]+nums[j]+nums[k];
                int fourth=target-sum;
                if(hashset.find(fourth)!=hashset.end()){
                    vector<int> temp={nums[i],nums[j],nums[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);

                }
                hashset.insert(nums[j]);
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}

int main(){

    

    return 0;
}
