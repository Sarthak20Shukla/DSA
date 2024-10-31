class Solution {
public:
    #define MAX 10000000000000LL
    long long helper(int r,vector<int>& robot,int f,vector<int>&fact,vector<vector<long long>> &dp){
        if(r<0) return 0;
        if(f<0) return MAX;
        if(dp[r][f]!=-1) return dp[r][f];
        long long inc=abs(robot[r]-fact[f])+helper(r-1,robot,f-1,fact,dp);
        long long exc=helper(r,robot,f-1,fact,dp);
        return dp[r][f]= min(inc,exc);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
         vector<int> fact;
         for(int i=0;i<factory.size();i++){
            int pos=factory[i][0];
            int cap=factory[i][1];
            for(int j=0;j<cap;j++)
            fact.push_back(pos);
         }
vector<vector<long long>> dp(robot.size(),vector<long long>(fact.size(),-1));
         return helper(robot.size()-1,robot,fact.size()-1,fact,dp);

    }
};