//Number of Provinces
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(int node,vector<int> adjls[],vector<int> &vis){
        vis[node]=1;
        for(auto it: adjls[node]){
            if(vis[it]==0){
                dfs(it,adjls,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
           int v=isConnected.size();
            
            vector<int> adjls[v];
     
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
       int cnt=0;
       vector<int> vis;
       for(int i=0;i<v;i++) 
        {
            vis.push_back(0);
        }
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,adjls,vis);
            }
        }
        return cnt;
    }
};

int main(){

    

    return 0;
}
