class Solution {
public:
int m,n;


void dfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& vis){
    if(i>=n||i<0||j>=m||j<0||vis[i][j]||grid[i][j]==0) return;

    vis[i][j]=true;
    dfs(grid,i,j+1,vis);
    dfs(grid,i,j-1,vis);
    dfs(grid,i+1,j,vis);
    dfs(grid,i-1,j,vis);
}
int numberofisland(vector<vector<int>>& grid){
int islands=0;
vector<vector<bool>> vis(n,vector<bool>(m));

for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    dfs(grid,i,j,vis);
                    islands++;
                }
        }
}
return islands;

}
    int minDays(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        int islands=numberofisland(grid);
        if(islands==0 || islands>1) return 0;
        else{
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
islands=numberofisland(grid);
        if(islands==0 || islands>1) return 1;
        grid[i][j]=1;
                }
            }
        }
        
    }
    return 2;

    }
};