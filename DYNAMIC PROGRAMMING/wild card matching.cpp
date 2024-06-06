//wild card matching
//recursion
class Solution {
public:
    bool f(int i,int j,string &s, string &t){
        if(i==0 || j==0) return true;
        if(i==0||j>0) return false;
        if(i>0||j==0){
            for(int ii=1;ii<=i;ii++){
                if(s[ii-1]=='*') return false;
            }
            return true;
        }

        if(s[i-1]==t[j-1] || s[i-1]=='?') return f(i-1,j-1,s,t);
        else {
            if(s[i-1]=='*') return f(i-1,j,s,t)||f(i,j-1,s,t);
         else return false;
        }
    }
    bool isMatch(string s, string t) {
        int n=s.size();
        int m=t.size();
        return f(n,m,s,t);
    }
};
//tabulation
#include <bits/stdc++.h>
bool wildcardMatching(string s, string t)
{
   // Write your code here.
int n=s.size();
        int m=t.size();
            vector<vector<bool>> dp(n + 1, vector<bool>(m+1, false));
        dp[0][0]=true;
        for(int j=1;j<=m;j++){
            dp[0][j]=false;
        }for(int j=1;j<=n;j++){
            bool flag=true;
            for(int i=1;i<=j;i++){
                if(s[i-1]!='*') {
                    flag=false;
                    break;
                }
            }
            dp[j][0]=flag;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 if(s[i-1]==t[j-1] || s[i-1]=='?') dp[i][j]=dp[i-1][j-1];
        else {
            if(s[i-1]=='*')  dp[i][j]=dp[i-1][j] ||dp[i][j-1];
             else  dp[i][j]=false;
        }
            }
        }
        return dp[n][m];
}
