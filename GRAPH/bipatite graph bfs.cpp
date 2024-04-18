//bipatite graph bfs
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
bool checkbfs(int start,int n,vector<vector<int>>& graph,int color[]){
    queue<int> q;
    q.push(start);
    color[start]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it : graph[node]){
            if(color[it]==-1){
                color[it]=!color[node];
                q.push(it);
            }
            else if(color[it]==color[node]) return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        int color[v];
        vector<int> adj;
        for(int i=0;i<v;i++){
            color[i]=-1;
        }for(int i=0;i<v;i++){
            if(color[i]==-1)
            if(checkbfs(i,v,graph,color)==false) return false;
        }
        return true;
    }
};

int main(){

    

    return 0;
}
