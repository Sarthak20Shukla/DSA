//	Find eventual safe states
#include<bits/stdc++.h>

using namespace std;
class Solution {
  public:
  bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[],int check[]) {
		vis[node] = 1;
		pathVis[node] = 1;
		check[node] = 0;
		for (auto it : adj[node]) {
		    if (!vis[it]) {
				if (dfsCheck(it, adj, vis, pathVis,check) == true){
					check[node]=0;
					return true;
			}}
			else if (pathVis[it]) {
			    check[node]=0;
				return true;
			}}
		
		check[node]=1;
		pathVis[node] = 0;
		return false;
	}
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here

        int vis[V]={0};
        int pathvis[V]={0};
        int check[V]={0};
        vector<int> safestates;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsCheck(i,adj,vis,pathvis,check);
            }
        }for(int i=0;i<V;i++){
            if(check[i]==1){
                safestates.push_back(i);
            }
        }
        sort(safestates.begin(), safestates.end());
        return safestates;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends

int main(){

    

    return 0;
}
