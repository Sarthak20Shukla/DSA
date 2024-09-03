class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string result="";
        string token="";
        while(ss>>token){
            result=token+" "+result;
        }
                int n=result.length();

        return result.substr(0,n-1);
    }
};

