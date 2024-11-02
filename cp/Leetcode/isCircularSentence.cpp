class Solution {
public:
    bool isCircularSentence(string sentence) {
        char c=sentence[0];
        int n=sentence.length();
        for(int i=0;i<n;i++){
            if(sentence[i]==' ' && sentence[i-1]!=sentence[i+1]) return false;
        }
        if(c==sentence[n-1]) return true;
         return false;
    }
};