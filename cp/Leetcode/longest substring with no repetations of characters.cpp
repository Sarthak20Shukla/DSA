class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int cnt=0;
        
        for(int i=0;i<n;i++){
            int hash[256]={0};
            for(int j=i;j<n;j++){
                if(hash[s[j]]==1) break;
                else {
                cnt=max(cnt,j-i+1);
                hash[s[j]]=1;
                }
            }
        }
        return cnt;
    }
};