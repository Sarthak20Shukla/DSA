//Minimum/Maximum Falling Path Sum
//recurrence
#include <bits/stdc++.h> 
 int f(int i,int j,vector<vector<int>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        if(j<0||j>=m) return -1e9;
        if(i==0) return matrix[0][j];
        int s=matrix[i][j]+f(i-1,j,matrix);
        int ld=matrix[i][j]+f(i-1,j-1,matrix);
        int ud=matrix[i][j]+f(i-1,j+1,matrix);
        return max(s,max(ld,ud));
        
    }
int getMaxPathSum(vector<vector<int>> &matrix)
{
     int n=matrix.size();
        int m=matrix[0].size();
        int maxi=INT_MIN;
        for(int i=0;i<m;i++){
            int ans = f(n - 1, i, matrix); // Calculate the maximum path sum for the last row
        maxi = max(maxi, ans);
        }
    return maxi;
}
//memoization
#include <bits/stdc++.h> 
 int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> &dp){
        int n=matrix.size();
        int m=matrix[0].size();
        if(j<0||j>=m) return -1e9;
        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int s=matrix[i][j]+f(i-1,j,matrix,dp);
        int ld=matrix[i][j]+f(i-1,j-1,matrix,dp);
        int ud=matrix[i][j]+f(i-1,j+1,matrix,dp);
        return dp[i][j]=max(s,max(ld,ud));
        
    }
int getMaxPathSum(vector<vector<int>> &matrix)
{
     int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int maxi=INT_MIN;
        for(int i=0;i<m;i++){
            int ans = f(n - 1, i, matrix,dp); // Calculate the maximum path sum for the last row
        maxi = max(maxi, ans);
        }
    return maxi;
}
//tabulation
int getMaxPathSum(vector<vector<int>> &matrix)
{
     int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
       
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                 int s=matrix[i][j]+dp[i-1][j];
              int ld = matrix[i][j];
            if (j - 1 >= 0) {
                ld += dp[i - 1][j - 1];
            } else {
                ld += -1e9; // A very large negative value to represent an invalid path
            }
                 int rd = matrix[i][j];
            if (j +1<m) {
                rd += dp[i - 1][j + 1];
            } else {
                rd += -1e9; // A very large negative value to represent an invalid path
            }
            dp[i][j]=max(s,max(ld,rd));
            }
        }
 int maxi=dp[n-1][0];
        for(int i=0;i<m;i++){
     // Calculate the maximum path sum for the last row
        maxi = max(maxi, dp[n-1][i]);
        }
    return maxi;
}
//space optimisation

int getMaxPathSum(vector<vector<int>> &matrix)
{
     int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
       vector<int>prev(m,0);
       vector<int>curr(m,0);
        for(int i=0;i<m;i++){
            prev[i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                 int s=matrix[i][j]+prev[j];
              int ld = matrix[i][j];
            if (j - 1 >= 0) {
                ld += prev[j - 1];
            } else {
                ld += -1e9; // A very large negative value to represent an invalid path
            }
                 int rd = matrix[i][j];
            if (j +1<m) {
                rd += prev[j + 1];
            } else {
                rd += -1e9; // A very large negative value to represent an invalid path
            }
     curr[j]=max(s,max(ld,rd));
            }
            prev=curr;
        }
   int maxi=prev[0];
        for(int i=0;i<m;i++){
     // Calculate the maximum path sum for the last row
        maxi = max(maxi, prev[i]);
        }
    return maxi;
}
