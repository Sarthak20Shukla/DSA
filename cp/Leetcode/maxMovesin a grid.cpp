class Solution {
public:
int n,m;
int helper(int row,int col,vector<vector<int>> &grid,vector<vector<int>>&dp){
    vector<int> dir{-1,0,1};
            int moves=0;
 if(dp[row][col]!=-1) return dp[row][col];
    for(auto &it:dir){
        int new_row=row+it;
        int new_col=col+1;
        if(new_row>=0 &&new_row<n && new_col>=0 &&new_col<m && grid[new_row][new_col]>grid[row][col]){
            moves=max(moves,1+helper(new_row,new_col,grid,dp));
        }

    }
 return dp[row][col]= moves;
}
    int maxMoves(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        int result=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            result=max(result,helper(i,0,grid,dp));
        }
        return result;
    }
};