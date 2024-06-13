//Partition Array for Maximum Sum
//recursion
class Solution {
public:
    int f(int i,int n,int k, vector<int>&arr){
        if(i==n) return 0;

        int len=0;
        int maxi=INT_MIN;
        int maxians=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=len*maxi+f(j+1,n,k,arr);
            maxians=max(maxians,sum);
        }
        return maxians;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        return f(0,n,k,arr);
    }
};

//memoisation
class Solution {
public:
    int f(int i,int n,int k, vector<int>&arr,vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int len=0;
        int maxi=INT_MIN;
        int maxians=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=len*maxi+f(j+1,n,k,arr,dp);
            maxians=max(maxians,sum);
        }
        return dp[i]=maxians;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return f(0,n,k,arr,dp);
    }
};

//tabulation
class Solution {
public:
    int f(int i,int n,int k, vector<int>&arr,vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int len=0;
        int maxi=INT_MIN;
        int maxians=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=len*maxi+f(j+1,n,k,arr,dp);
            maxians=max(maxians,sum);
        }
        return dp[i]=maxians;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
             int len=0;
        int maxi=INT_MIN;
        int maxians=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=len*maxi+f(j+1,n,k,arr,dp);
            maxians=max(maxians,sum);
        }
         dp[i]=maxians;
        }
        return dp[0];
    }
};