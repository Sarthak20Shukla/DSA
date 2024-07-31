//memoisation

class Solution {
public:
int width;
    int solve(vector<vector<int>>&dp,vector<vector<int>>& books, int i,int remW,int maxHt){
        if(i>=books.size()) return maxHt;
        if(dp[i][remW]!=-1) return dp[i][remW];
        int keep=INT_MAX;
        int skip=INT_MAX;
        int bookWdth=books[i][0];
        int bookHght=books[i][1];
        if(bookWdth<=remW){
            keep=solve(dp,books,i+1,remW-bookWdth,max(maxHt,bookHght));
        }
         skip=maxHt+solve(dp,books,i+1,width-bookWdth,bookHght);

         return dp[i][remW]=min(skip,keep);

    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        int remW=shelfWidth;
        width=shelfWidth;
        return solve(dp,books,0,remW,0);
    }
};
