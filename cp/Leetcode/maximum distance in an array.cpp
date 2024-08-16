class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n=arrays.size();
        int m=arrays[0].size();

        int uttar=0;
        int s=arrays[0][0];

        int g=arrays[0][m-1];
        for(int i=1;i<n;++i){
                int m=arrays[i].size();
                uttar=max(uttar,abs(arrays[i][m-1]-s));
                uttar=max(uttar,abs(g-arrays[i][0]));
               s =min(s,arrays[i][0]);
               g =max(g,arrays[i].back());
            
        }
        return uttar;
    }
};