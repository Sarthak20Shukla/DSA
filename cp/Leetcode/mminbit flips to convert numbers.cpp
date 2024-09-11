class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorval = start^goal;
        int cnt=0;
        while(xorval>=1){
            cnt+=xorval&1;
            xorval >>=1;
        }
        return cnt;
        
    }
};