//count nodes in a binary tree
#include<bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int leftheight(BinaryTreeNode<int> *root){
    int height=0;
    while(root){
        height++;
        root=root->left;
    }
    return height;
}
int rightheight(BinaryTreeNode<int> *root){
    int height=0;
    while(root){
        height++;
        root=root->right;
    }
    return height;
}
int countNodes(BinaryTreeNode<int> *root) {
  // Write your code here.
  if(root==NULL) return 0;
  int lh=leftheight(root);
  int rh=rightheight(root);
  if(lh==rh) return pow(2,lh)-1;
  return 1+countNodes(root->left)+countNodes(root->right);
}

int main(){

    

    return 0;
}
