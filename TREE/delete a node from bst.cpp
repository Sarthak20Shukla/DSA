//delete a node from bst
#include<bits/stdc++.h>

using namespace std;

/*************************************************************
    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
BinaryTreeNode<int>* findlastright(BinaryTreeNode<int>* root){
    if(root->right==NULL) return root;
    return findlastright(root->right);
}

BinaryTreeNode<int>* helper(BinaryTreeNode<int>* root){
    if(root->left==NULL) return root->right;
    else if(root->right == NULL) return root->left;
    BinaryTreeNode<int>* rightchild=root->right;
    BinaryTreeNode<int>* lastright=findlastright(root->left);
    lastright->right=rightchild;
    return root->left;
}
BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key) {
    // Write your code here.
    if(root==NULL) return nullptr;
     if(root->data==key) return helper(root);
    BinaryTreeNode<int>* curr=root;
    while(root!=NULL){
        if(root->data>key){
            if(root->left!=NULL && root->left->data==key ){
                root->left=helper(root->left);
                break;

            } else root=root->left;
        } else {
            if(root->right!=NULL && root->right->data==key){
                root->right=helper(root->right);
                break;
            } else root=root->right;
        }
    }
    return curr;
}


int main(){

    

    return 0;
}
