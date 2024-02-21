//symmetry of a binary tree
#include<bits/stdc++.h>

using namespace std;

/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
bool isSymmetrichelp(TreeNode<int> *left,TreeNode<int> *right){
    if(left==NULL||right==NULL) return left==right;
    if(left->data!=right->data) return false;
    return isSymmetrichelp(left->left,right->right) && isSymmetrichelp(left->right,right->left);

}
bool isSymmetric(TreeNode<int> *root)
{
    // Write your code here
    return root==NULL||isSymmetrichelp(root->left,root->right);
}

int main(){

    

    return 0;
}
