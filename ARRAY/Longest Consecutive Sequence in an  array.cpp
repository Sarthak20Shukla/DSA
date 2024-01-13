#include<bits/stdc++.h>

using namespace std;

int longestConsecutiveoptimal(vector<int>& nums) {
    unordered_set<int>st;
    int n=nums.size();
    int largest=1;
    
    if(n==0) return 0;
    else{
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    x++;
                    cnt++;
                }
            }
            largest=max(largest,cnt);
        }
    return largest;}
    }

int longestConsecutivebetter(vector<int>& nums) {
          sort(nums.begin(),nums.end());
    int n=nums.size();
    int largest=1,cnt=0,lastsmall=INT_MIN;
    if(n==0) return 0;
    else{
    for(int i=0;i<n;i++){
        if(nums[i]-1==lastsmall){
            cnt++;
            lastsmall=nums[i];
        }
        else if(nums[i]!=lastsmall){
            cnt=1;
            lastsmall=nums[i];
        }
        largest=max(largest,cnt);
    }



    return largest;}
    }
int main(){

    

    return 0;
}
