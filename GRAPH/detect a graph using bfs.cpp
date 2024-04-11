//detect a graph using bfs
#include<bits/stdc++.h>

using namespace std;

class Graph {

public:
bool detect(vector<int> adj[],int vis[],int src){
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push({it,node});
            }
            else if(parent != it) return true;
        }
    }
    return false;
}
    bool detectCycle(int V, vector<int> adj[]) {
        // Write your code here.
        int vis[V]={0};
        for(int i=0;i<V;i++){
        if (!vis[i]) {
            if (detect(adj, vis, i))
                return true;
        }
        }
        return false;
    }
};

int main(){

    

    return 0;
}
