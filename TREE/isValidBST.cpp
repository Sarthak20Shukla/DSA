//BST
#include<bits/stdc++.h>

using namespace std;

bool isValidBST(vector<int> &order){
    // Write your code here.
    int cnt=0;

    for(int i=0;i<order.size()-1;i++){
        if(order[i+1]<=order[i]) return false;
    }
    return true;
    
}


int main(){

    

    return 0;
}
