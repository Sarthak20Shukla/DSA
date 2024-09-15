class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> countVowels(5,0);
        unordered_map<string,int> mp;
        string str="00000";
        mp[str]=-1;
        int result=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'){
                countVowels[0]=(countVowels[0]+1)%2;
            } else if(s[i]=='e'){
                countVowels[1]=(countVowels[1]+1)%2;
            }else if(s[i]=='i'){
                countVowels[2]=(countVowels[2]+1)%2;
            }
            else if(s[i]=='o'){
                countVowels[3]=(countVowels[3]+1)%2;
            }
            else if(s[i]=='u'){
                countVowels[4]=(countVowels[4]+1)%2;
            }
        str="";
        for(int j=0;j<5;j++){
            str+=to_string(countVowels[j]);
        }
        if(mp.find(str)!=mp.end()){
            result=max(result,i-mp[str]);
        } else{
            mp[str]=i;
        }
        }
        return result;
    }
};