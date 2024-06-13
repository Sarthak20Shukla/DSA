//palindrome partitioning II
//recursion
class Solution {
public:
bool ispalindrome(int i,int j,string s){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int f(int i,int n,string s){
    if(i==n) return 0;
    int cost;
    int mincost=INT_MAX;
    string temp="";
    for(int j=i;j<=n;j++){
        if(ispalindrome(i,j,s)){
         cost=1+f(j+1,n,s);
        
        mincost=min(mincost,cost);
    }}
    return mincost;
}
    int minCut(string s) {
        int n=s.size();
        return f(0,n,s)-1;
    }
};
//memoisation
class Solution {
public:
bool ispalindrome(int i,int j,string &s){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int f(int i,int n,string s,vector<int>& dp){
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int cost;
    int mincost=INT_MAX;
    string temp="";
    for(int j=i;j<=n;j++){
        if(ispalindrome(i,j,s)){
         cost=1+f(j+1,n,s,dp);
        
        
        mincost=min(mincost,cost);
        }
    }
    return dp[i]=mincost;
}
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return f(0,n,s,dp)-1;
    }
};
//tabulation
 int minCut(string s) {
        int n=s.size();
        int cost;
        vector<int> dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int mincost=1e9;
            for(int j=i;j<=n;j++){
        if(ispalindrome(i,j,s)){
         cost=1+dp[j+1];
        mincost=min(mincost,cost);
        }
    }
     dp[i]=mincost;
            }
        return dp[0]-1;
    }
};