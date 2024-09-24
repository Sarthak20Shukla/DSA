class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;

        for(int it:arr1){
            while(!st.count(it) && it>0){
            st.insert(it);
            it/=10;
            }
        }
        int x=0;
        for(int it2:arr2){
            while(!st.count(it2) && it2>0){
            it2/=10;
            }
            if(it2>0){
                x=max(x,static_cast<int>(log10(it2)+1));
            }
        }
        return x;
    }
};