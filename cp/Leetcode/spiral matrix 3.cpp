class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>ans;
        int x_direction[]={0,1,0,-1};
        int y_direction[]={1,0,-1,0};
        int dir=0;
        int steps=0;
        ans.push_back({rStart,cStart});
        while(ans.size()!=rows*cols){
            if(dir==0 || dir==2){
                steps++;
            } 
            for(int cnt=0;cnt<steps;cnt++){
                    rStart+=x_direction[dir];
                    cStart+=y_direction[dir];
                if((rStart>=0 && rStart<rows) && (cStart>=0 && cStart<cols)){
                    
                    ans.push_back({rStart,cStart});
                }
            }
            dir=(dir+1)%4;
        }
        return ans;
    }
};