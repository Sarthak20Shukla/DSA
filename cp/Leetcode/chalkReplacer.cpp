class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(int &it:chalk){
            sum+=it;
        }
        int remchalk=k%sum;
        for(int i=0;i<chalk.size();i++){
            if(remchalk<chalk[i]){
                return i;
            }
remchalk-=chalk[i];
        }

        return -1;
        
    }
};