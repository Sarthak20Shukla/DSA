// recursion
class Solution {
public:
bool solve(string s, string p){
    if(p.length()==0) return (s.length()==0);
    bool fcm=false;
    if((s.length()>0) && (s[0]==p[0]|| p[0]=='.')) fcm=true;
    if(p[1]=='*') {
        bool not_take=solve(s,p.substr(2));
        bool take=fcm && solve(s.substr(1),p);
        return not_take|| take;
    } 
            return fcm && solve(s.substr(1),p.substr(1));
    
}
    bool isMatch(string s, string p) {
        return solve(s,p);
    }
};

class Solution {
public:
bool solve(int i,int j,string s, string p){
     int n=s.length();
     int m=p.length();
    if(p.length()==j) return (s.length()==i);
    bool fcm=false;
    if((s.length()>i) && (s[i]==p[j]|| p[j]=='.')) fcm=true;
    if(p[j+1]=='*') {
        bool not_take=solve(i,j+2,s,p);
        bool take=fcm && solve(i+1,j,s,p);
        return not_take|| take;
    } 
            return fcm && solve(i+1,j+1,s,p);
    
}
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<bool>>dp(n,vector<bool>(m,false));
        return solve(0,0,s,p);
    }
};

//memoisation

