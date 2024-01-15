//pascal triangle
#include<bits/stdc++.h>

using namespace std;

vector<int> generateAns(int row){
    
    vector<int> ansRow;
    long long ans=1;
    ansRow.push_back(1);

    for(int i=1;i<row;i++){
        ans=ans*(row-i);
        ans=ans/(i);
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> pascalTriangleoptimal(int N) {
    // Write your code here.
    vector<vector<int>> ans;
    for(int i=1;i<=N;i++){
        ans.push_back(generateAns(i));
    }
    return ans;
}


int main(){

    

    return 0;
}
