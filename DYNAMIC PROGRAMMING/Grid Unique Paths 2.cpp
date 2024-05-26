//Grid Unique Paths 2  with obstacles
//recursion
int helper(int i,int j){
     if (i > 0 && j > 0 && maze[i][j] == -1) return 0; // If there's an obstacle at (i, j), return 0
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    int up=helper(i-1,j);
    int left=helper(i,j-1);
    return up+left;
}
    int uniquePaths(int m, int n) {
        return helper(m-1,n-1);
    }
};
//memoization
int mazeObstaclesUtil(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &dp) {
    // Base cases
    if (i > 0 && j > 0 && maze[i][j] == -1) return 0; // If there's an obstacle at (i, j), return 0
    if (i == 0 && j == 0) return 1; // If we reach the destination (0, 0), return 1
    if (i < 0 || j < 0) return 0; // If we go out of bounds, return 0
    if (dp[i][j] != -1) return dp[i][j]; // If the result is already computed, return it

    // Recursive calls to explore paths from (i, j) to (0, 0)
    int up = mazeObstaclesUtil(i - 1, j, maze, dp);
    int left = mazeObstaclesUtil(i, j - 1, maze, dp);

    // Store the result in the DP table and return it
    return dp[i][j] = up + left;
}

// Main function to count paths with obstacles in a maze
int mazeObstacles(int n, int m, vector<vector<int>> &maze) {
    vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table to memoize results
    return mazeObstaclesUtil(n - 1, m - 1, maze, dp); // Start from the bottom-right corner
}

//tabulation
int mod=(int)(1e9+7);
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
        int dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==-1) dp[i][j]= 0;
               else if(i==0 && j==0) dp[i][j]=1;
                else {
                    int up=0,left=0;
                   if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];

                    dp[i][j]=(up+left)%mod;
                }
            }
        }
        return dp[n-1][m-1];
}
