class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        int n=details.size();
       
            for(auto ch:details){
                int t=ch[11];
                int o=ch[12];
                if(t>'6'||(t=='6' && o>'0')) cnt++;
            }
            return cnt;
        
    }
};