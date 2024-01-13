//Rearrange Array Elements by Sign | 2 Varieties of same Problem
#include<bits/stdc++.h>

using namespace std;

vector<int> alternateNumbers(vector<int>&a) {
    //if different number of positive and negatives are present
    // Write your code here.
    vector<int>pos,neg;
    int n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]<0){
            neg.push_back(a[i]);
        } else pos.push_back(a[i]);
    }
    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
            a[i*2]=pos[i];
            a[i*2+1]=neg[i];
        }
        int index=2*neg.size();
        for(int i=neg.size();i<pos.size();i++){
            a[index]=pos[i];
            index++;
        }
    } else{
        for(int i=0;i<pos.size();i++){
            a[i*2]=pos[i];
            a[i*2+1]=neg[i];
        }
        int index=2*pos.size();
        for(int i=pos.size();i<neg.size();i++){
            a[index]=neg[i];
            index++;
        }
    }
    return a;
    }
vector<int> rearrangeArray(vector<int>& nums) {
    //if same number of positive and negatives are present
        //bruteforce 
        int n = nums.size();
        vector<int>pos,neg;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }
            else pos.push_back(nums[i]);
        }
        for(int i=0;i<n/2;i++){
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }
        return nums;
        //optimal
        int n=nums.size();
        vector<int> ans(n,0);
        int pos=0,neg=1;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans[neg]=nums[i];
                neg+=2;
            }else {
                ans[pos]=nums[i];
                pos+=2;
            }
        }
        return ans;
    }

int main(){

    

    return 0;
}
