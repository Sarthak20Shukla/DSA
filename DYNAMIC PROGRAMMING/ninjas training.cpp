//ninjas training
//recursion
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int fun(int day,int last,vector<vector<int>>& points){
     
      if(day==0){
           int maxi=0;
          for(int i=0;i<3;i++){
              if(i!=last){
                  maxi=max(maxi,points[0][i]);
              }
          }
          return maxi;
      }
      int maxi=0;
      for(int i=0;i<3;i++){
          if(i!=last){
              maxi=max(maxi,points[day][i]+fun(day-1,i,points));
          }
      }
      return maxi;
  }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        return fun(n-1,3,points);
    }
};

//memoization
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int fun(int day,int last,vector<vector<int>>& points,vector<vector<int>>& dp){
     if(dp[day][last]!=-1) return dp[day][last];
      if(day==0){
           int maxi=0;
          for(int i=0;i<3;i++){
              if(i!=last){
                  maxi=max(maxi,points[0][i]);
              }
          }
          return maxi;
      }
      int maxi=0;
      for(int i=0;i<3;i++){
          if(i!=last){
              maxi=max(maxi,points[day][i]+fun(day-1,i,points,dp));
          }
      }
      return dp[day][last]=maxi;
  }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return fun(n-1,3,points,dp);
    }
};

//tabular
class Solution {
  public:
 
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(4,0));
        dp[0][0] = max(points[0][1],points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
        
        for(int day=1;day<n;day++){
            for(int last=0;last<4;last++){
                dp[day][last]=0;
                for(int i=0;i<3;i++){
                 if(i!=last){
             dp[day][last] =max(dp[day][last],points[day][i]+dp[day-1][i]);
          }
      }
            }
        }
              return dp[n-1][3];
    }
};

//space optimisation
class Solution {
  public:
 
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<int> prev(4,0);
        prev[0] = max(points[0][1],points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
        
        for(int day=1;day<n;day++){
             vector<int> temp(4,0);
            for(int last=0;last<4;last++){
                temp[last]=0;
                for(int i=0;i<3;i++){
                 if(i!=last){
             temp[last] =max(temp[last],points[day][i]+prev[i]);
          }
      }
            }
            prev=temp;
        }
              return prev[3];
    }
};