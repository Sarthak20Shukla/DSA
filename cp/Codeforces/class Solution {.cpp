class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.length();
        int leftbCount=0;
        int rightacount=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(s[j]=='b') leftbCount++;
                
            }
            for(int j=i+1;j<n;j++){
                if(s[j]=='a') rightacount++;
            }
            
            ans=min(ans,leftbCount+rightacount);
        }
        return ans;
        
    }
};