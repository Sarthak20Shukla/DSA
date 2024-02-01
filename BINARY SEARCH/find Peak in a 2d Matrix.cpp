//find Peak in a 2d Matrix
#include<bits/stdc++.h>

using namespace std;

int maxelement(vector<vector<int>> &g,int n,int m,int col){
    int index=-1, maxel=-1;
    for(int i=0;i<n;i++){
        if(g[i][col]>maxel){
            maxel=g[i][col];
            index=i;
        }
    }

    return index;
}
vector<int> findPeakGrid(vector<vector<int>> &g){
    // Write your code here.
    int n=g.size();
    int m=g[0].size();
    int low=0,high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int row=maxelement(g,n,m,mid);
        int left=mid-1 >= 0?g[row][mid-1]: -1;

        int right=mid+1 <=m?g[row][mid+1]: -1;
        if(g[row][mid]>left && g[row][mid]>right) return {row,mid};
        else if(g[row][mid]<left) high=mid-1;
        else low=mid+1;
    }    
    return {-1,-1};
}

int main(){

    

    return 0;
}
