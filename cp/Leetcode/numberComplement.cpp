class Solution {
public:
    int findComplement(int num) {
        vector<int> ans;
        int result=0;
        while(num!=0){
            ans.push_back(num%2);
            num=num/2;

        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]==1) ans[i]=0;
            else if(ans[i]==0) ans[i]=1;
        }
        for(int i=ans.size()-1;i>=0;i--){
            result=result*2+ans[i];
        }
        return result;
        
    }
};