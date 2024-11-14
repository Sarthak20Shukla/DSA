class Solution {
public:
    bool possibleOutcome(int x,vector<int>& quantities,int shop){

        for(int &it:quantities){
            shop-=(it+x-1)/x;
            if(shop<0) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1;
        int r=*max_element(begin(quantities),end(quantities));
                    int result=0;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(possibleOutcome(mid,quantities,n)){
                result=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return result;
    }
};