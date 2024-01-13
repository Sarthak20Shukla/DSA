#include<bits/stdc++.h>

using namespace std;
vector<int> superiorElementsbrute(vector<int>&a) {
    // Write your code here.
    int n=a.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        leader=true;
        for(int j=i+1;j<n;j++){
            if(a[j]>a[i]){
                leader=false;
                break;
            }
        }
        if(leader==true){
            ans.add(a[i]);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
vector<int> superiorElementsoptimal(vector<int>&a) {
    // Write your code here.
    int n=a.size();int maxi=INT_MIN;
    vector<int> ans;
    for(int i=n-1;i>=0;i--){
        if(a[i]>maxi){
            ans.push_back(a[i]);
        }
        maxi=max(maxi,a[i]);
    }

    sort(ans.begin(),ans.end());
    return ans;
}
int main(){

    

    return 0;
}
