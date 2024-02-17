//postorderTraversal
#include<bits/stdc++.h>

using namespace std;

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
 vector<int> res;
 void preOrder2(TreeNode* root){
      if(root== NULL) return;
    
    preOrder2(root->left);
 
    preOrder2(root->right);
       res.push_back(root->data);
 }
vector<int> postorderTraversal(TreeNode *root)
{
    // Write your code here.
    preOrder2(root);
    return res;
}

int main(){

    

    return 0;
}
