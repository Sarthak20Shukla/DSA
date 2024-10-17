class Solution {
public:
    int maximumSwap(int num) {

        string s=to_string(num);
        int n=s.length();
        vector<int> maxRight(n);
        maxRight[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            int maxelindex=maxRight[i+1];
            int maxel=s[maxelindex];
            maxRight[i]=(s[i]>maxel) ? i:maxelindex;
        }
        for(int i=0;i<n;i++){
            int maxRightIndex=maxRight[i];
            int maxRightElement=s[maxRightIndex];
            if(s[i]<maxRightElement){
                swap(s[i],s[maxRightIndex]);
                return stoi(s);
            }
        }
        return num;
    }
};