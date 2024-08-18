class Solution {
public:
    int nthUglyNumber(int n) {
        int x=0,y=0,z=0;
        vector<int> dp(n);
        dp[0]=1;
        for(int i=1;i<n;i++){
            int mul2=2*dp[x];
            int mul3=3*dp[y];
            int mul5=5*dp[z];

            dp[i]=min(mul2,min(mul3,mul5));
            if(dp[i]==mul2) x++;
            if(dp[i]==mul3) y++;
            if(dp[i]==mul5) z++;

        }
        return dp[n-1];
    }
};