//maximum no of points with cost
//memoization
class Solution {
public:
    typedef long long ll;
    int n,m;
    ll helper(vector<vector<int>>& points,int prevcol,int row,vector<vector<int>>&dp){
        if(row>=n)  return 0;
        if(dp[row][prevcol]!=-1) return dp[row][prevcol];
        ll ans=0;
        for(int i=0;i<m;i++){
            ll temp=points[row][i]-abs(i-prevcol)+helper(points,i,row+1,dp);
            ans=max(ans,temp);
        }
        return dp[row][prevcol]=ans;
    }
    long long maxPoints(vector<vector<int>>& points) {
        n=points.size();
        m=points[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        ll ans=0;
        for(int i=0;i<m;i++){
            ll temp=points[0][i]+helper(points,i,1,dp);
            ans=max(ans,temp);
        }
        return ans;
    }
};

//tabution
long long maxPoints(vector<vector<int>>& points) {
        n=points.size();
        m=points[0].size();
        vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
        for (int i = 0; i < m; i++)
        {
            dp[0][i] = points[0][i]; 
        }

        //For every row after 0th we traverse from both sides and take maximum
        for (int i = 1; i < n; i++)
        {
            // Find max value till that column from left and right
            vector<ll> leftMax(m), rightMax(m);

            //Filling leftMax table
            leftMax[0] = dp[i - 1][0];
            for (int j = 1; j < m; j++)
            {
                leftMax[j] = max(leftMax[j - 1] - 1, dp[i - 1][j]);
            }

            //Filling rightMax table
            rightMax[m - 1] = dp[i - 1][m - 1];
            for (int j = m - 2; j >= 0; j--)
            {
                rightMax[j] = max(rightMax[j + 1] - 1, dp[i - 1][j]);
            }

            // In the end we find the max value for every col in that ith row
            for (int j = 0; j < m; j++)
            {
                dp[i][j] = points[i][j] + max(leftMax[j], rightMax[j]);
            }
        }


        // The answer will be the max value in the last row.
        ll ans = 0;
        for (int j = 0; j < m; j++)
        {
            ans = max(ans, dp[n - 1][j]);
        }

        return ans;
    }
};