//check if a binary tree is balanced or not
#include<bits/stdc++.h>

using namespace std;

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int heightdifference(TreeNode<int>* root){
if(root==nullptr) return 0;
int lh=heightdifference(root->left);
if(lh==-1) return -1;
int rh=heightdifference(root->right);
if(rh==-1) return -1;

if(abs(lh-rh)>1) return -1;

return max(lh,rh)+1;

}

bool isBalancedBT(TreeNode<int>* root){
    // Write your code here.
    return heightdifference(root) !=-1;

}


int main(){

    

    return 0;
}
