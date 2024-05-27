//triangular grids
//recursion
class Solution {
public:
int f(int i,int j,vector<vector<int>>& triangle){
    int n=triangle.size();
        int m=triangle[0].size();
    if(i==n-1) return triangle[i][j];
    int d=triangle[i][j]+f(i+1,j,triangle);
    int dg=triangle[i][j]+f(i+1,j+1,triangle);
    return min(d,dg);
    
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[0].size();
        return f(0,0,triangle);
    }
};
//memoization
class Solution {
public:
int f(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
    int n=triangle.size();
        int m=triangle[0].size();
        if(dp[i][j]!=-1) return dp[i][j];
    if(i==n-1) return triangle[i][j];
    int d=triangle[i][j]+f(i+1,j,triangle,dp);
    int dg=triangle[i][j]+f(i+1,j+1,triangle,dp);
    return dp[i][j]=min(d,dg);
    
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[0].size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,triangle,dp);
    }
};
//tabulation
 int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[0].size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];

        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d=triangle[i][j]+dp[i+1][j];
                int dg=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(d,dg);
            }
        }
        return dp[0][0];
    }
};