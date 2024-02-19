//Boundary traversal of a binary tree
#include<bits/stdc++.h>

using namespace std;

/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int> * root) {
  return !root -> left && !root -> right;
}
void addLeft(TreeNode<int> * root,vector<int>&res){
TreeNode<int> *curr=root->left;
while(curr){
    if(!isLeaf(root)) res.push_back(curr->data);
    if(curr->left) curr=curr->left;
    else curr=curr->right;
}
}
void addRight(TreeNode<int> * root,vector<int>&res){
   TreeNode<int> *curr=root->right;
   vector<int> tmp;
while(curr){
    if(!isLeaf(root)) res.push_back(curr->data);
    if(curr->right) curr=curr->right;
    else curr=curr->left;
} for (int i = tmp.size() - 1; i >= 0; --i) {
    res.push_back(tmp[i]);
}
void leafnodes(TreeNode<int> * root,vector<int>&res){
    if (isLeaf(root)) {
    res.push_back(root -> data);
    return;
  }
  if (root -> left) leafnodes(root -> left, res);
  if (root -> right) leafnodes(root -> right, res);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push(root->data);
    addLeft(root, res);
    leafnodes(root, res);
    addRight(root, res);
    return res;
}


int main(){

    

    return 0;
}
