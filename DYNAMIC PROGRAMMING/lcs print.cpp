//lcs print
//tabulation
int n=s1.size(),m=s2.size();
            vector<vector<int>> dp(n,vector<int>(m,0));
            for(int j=0;j<m;j++){
                if(s1[0]==s2[j]) dp[0][j]=1;
                else dp[0][j]= j==0 ? 0 : dp[0][j-1];
            }
            for(int i=0;i<n;i++){
                if(s1[i]==s2[0]) dp[i][0]=1;
                else dp[i][0]= i==0 ? 0 : dp[i-1][0];
            }
            for(int i=1;i<n;i++){
                for(int j=1;j<m;j++){
                    if(s1[i]==s2[j]) dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
            
            vector<vector<unordered_set<string>>> dpvec(n,vector<unordered_set<string>>(m));
            if(dp[0][0]==1) dpvec[0][0]={string(1,s1[0])};
            for(int j=1;j<m;j++){
                dpvec[0][j]= dpvec[0][j-1];
                if(s1[0]==s2[j]) dpvec[0][j].insert(string(1,s2[j]));
            }
            for(int i=1;i<n;i++){
                dpvec[i][0] = dpvec[i-1][0];
                if(s1[i]==s2[0]) dpvec[i][0].insert(string(1,s1[i]));
            }
            
            for(int i=1;i<n;i++){
                for(int j=1;j<m;j++){
                    if(s1[i]==s2[j]){
                        if(dp[i][j]==1) dpvec[i][j].insert(string(1,s1[i]));
                        else for(auto str: dpvec[i-1][j-1]){
                            dpvec[i][j].insert(str+s1[i]);
                        }
                    }
                    else{
                        if(dp[i][j-1]>dp[i-1][j]) dpvec[i][j]=dpvec[i][j-1];
                        else if(dp[i][j-1]<dp[i-1][j]) dpvec[i][j]=dpvec[i-1][j];
                        else{
                            dpvec[i][j]=dpvec[i-1][j];
                            for(auto str: dpvec[i][j-1]){
                                dpvec[i][j].insert(str);
                            }
                        }
                    }
                    
                }
            }
            
            vector<string> ans;
            for(auto str:dpvec[n-1][m-1]) ans.push_back(str);
            sort(ans.begin(),ans.end());
            return ans;
