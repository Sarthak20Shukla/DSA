//shortest path in binary maze 
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> dest) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        if(src.first==dest.first && src.second==dest.second) return 0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src.first,src.second}});
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[src.first][src.second]=0;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            q.pop();
            for(int i=0;i<4;i++){
               int newrow=r+dr[i];
               int newcol=c+dc[i]; 
               if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]==1 && dis+1<dist[newrow][newcol]){
                   dist[newrow][newcol]=1+dis;
                   if(newrow==dest.first && newcol==dest.second)
                       return dis+1;
                q.push({1+dis,{newrow,newcol}});
                   
               }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends