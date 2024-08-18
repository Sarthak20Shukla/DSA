class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int res=0;
        for(int i=0;i<s.length();i++){
            int cnt1=0;
            int cnt0=0;
            for(int j=i;j<s.length();j++){
                if(s[j]=='1') cnt1++;
                else cnt0++;
                if(cnt1<=k || cnt0<=k) res++;
            }

        }
        return res;
        
    }
};