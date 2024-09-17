class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        unordered_map<string,int> mp;
        string word="";
        for(char ch:s1){
            if(ch==' '){
                mp[word]++;
                word="";
            } else {
                word+=ch;
            }
           
        }
         mp[word]++;
            word="";
            for(char ch:s2){
            if(ch==' '){
                mp[word]++;
                word="";
            } else {
                word+=ch;
            }
           
        }
        mp[word]++;
        for(auto it:mp){
            if(it.second==1) ans.push_back(it.first);
        }
        return ans;
    }
};