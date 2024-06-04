//Distinct Subsequences
//recursion
class Solution {
public:
int f(int i,int j,string s, string t){
        if(j==0) return 1;

    if(i==0) return 0;

    if(s[i-1]==t[j-1]) {
        return f(i-1,j-1,s,t)+f(i-1,j,s,t);
    }  return f(i-1,j,s,t);
}
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        return f(n,m,s,t);
    }
};
//memoization
class Solution {
public:
int f(int i,int j,string &s, string &t, vector<vector<int>> &dp){
    if(j==0) return 1;

    if(i==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i-1]==t[j-1]) {
        return dp[i][j]=f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
    }  return dp[i][j]=f(i-1,j,s,t,dp);
}
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
         vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return f(n,m,s,t,dp);
    }
};

//tabulation
class Solution {
public:

    int numDistinct(string s, string t) {
        int mod = 1e9 + 7;
        int n=s.size();
        int m=t.size();
         vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
         for(int i=0;i<=n;i++){
            dp[i][0]=1;
         }
         for(int j=1;j<=m;j++){
            dp[0][j]=0;
         }

         for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

    if(s[i-1]==t[j-1]) {
         dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]) % mod;
    } else   dp[i][j]=dp[i-1][j] % mod ;
         }
         }
return dp[n][m];
    }
};
//space optimisation
class Solution {
public:

    int numDistinct(string s, string t) {
        int mod = 1e9 + 7;
        int n=s.size();
        int m=t.size();
         vector<long long>prev(m+1, 0);
         vector<long long>curr(m+1, 0);

            curr[0]=prev[0]=1;

         for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

    if(s[i-1]==t[j-1]) {
         curr[j]=(prev[j-1]+prev[j]) % mod;
    } else   curr[j]=prev[j] % mod ;
         }
         prev=curr;
         }
return prev[m];
    }
};