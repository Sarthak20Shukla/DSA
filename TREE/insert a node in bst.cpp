//insert a node in bst
#include<bits/stdc++.h>

using namespace std;

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left, *right;
        TreeNode() : val(0), left(NULL), right(NULL) {}
        TreeNode(T x) : val(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : val(x), left(left), right(right) {}
    };


************************************************************/

TreeNode<int>* insertionInBST(TreeNode<int>* root, int val)
{
    // Write your code here.
    TreeNode<int>* curr=root;
    if(root==nullptr) return   new TreeNode(val);
    while(true){
    if(curr->val<=val){
        if(curr->right!=NULL) curr=curr->right;
        else {
            curr->right=new TreeNode(val);
            break;
        }

    }else{
         if(curr->left!=NULL) curr=curr->left;
        else {
            curr->left=new TreeNode(val);
            break;
        }
    }}
    return root;
}

int main(){

    

    return 0;
}
