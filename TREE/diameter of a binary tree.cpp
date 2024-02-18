//diameter of a binary tree
#include<bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int height(TreeNode<int> *root,int &maxi){
    if(root == NULL) return 0;
    int lh=height(root->left,maxi);
    int rh=height(root->right,maxi);
    maxi=max(lh+rh,maxi);

    return 1+max(lh,rh);
}
int diameterOfBinaryTree(TreeNode<int> *root){
	// Write Your Code Here.
    int maxi=0;
    height(root,maxi);
    return maxi;
}



int main(){

    

    return 0;
}
