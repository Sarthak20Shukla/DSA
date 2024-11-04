class Solution {
public:
    string compressedString(string word) {
        string comp="";
        int n=word.length();
        char ch=word[0];
        int cnt=1;
        for(int i=1;i<n;i++){
            if(word[i]==ch && cnt<9){
                cnt++;
            } else {
                comp.push_back(cnt+'0');
                comp.push_back(ch);
                ch=word[i];
                cnt=1;
            }
        }
                comp.push_back(cnt+'0');
                comp.push_back(ch);
                return comp;
    }
};