//right view of a binary tree
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
void recursion(TreeNode* root,int level,vector<int> &ans){
    if(root==NULL) return;
    if(level==ans.size()){
        ans.push_back(root->val);
    }
     recursion(root->right, level+1, ans);
    recursion(root->left, level+1, ans);
   
}

    vector<int> rightSideView(TreeNode* root) {
         vector<int> ans;
    recursion(root,0,ans);
    return ans;
    }
};

int main(){

    

    return 0;
}
