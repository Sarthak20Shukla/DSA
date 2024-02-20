//left view of a binary tree
#include<bits/stdc++.h>

using namespace std;

void recursion(BinaryTreeNode<int>* root,int level,vector<int> &ans){
    if(root==NULL) return;
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    recursion(root->left, level+1, ans);
    recursion(root->right, level+1, ans);
}
vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int> ans;
    recursion(root,0,ans);
    return ans;
}

int main(){

    

    return 0;
}
