//Construct Binary Tree From Inorder and Preorder Traversal
#include<bits/stdc++.h>

using namespace std;

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
TreeNode<int> *buildTree(vector<int> &preorder,int prestart,int preend,vector<int> &inorder,int instart,int inend,map<int,int> &imap ){
    if(prestart>preend||instart>inend) return nullptr;
    TreeNode<int> *root= new TreeNode(preorder[prestart]);
    int inroot=imap[root->data];
    int numleft=inroot-instart;
    root->left=buildTree(preorder,prestart+1,prestart+numleft,inorder,instart,inroot-1,imap);
    root->right=buildTree(preorder,prestart+numleft+1,preend,inorder,inroot+1,inend,imap);
    return root;
    
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    map<int,int> imap;
    for(int i=0;i<inorder.size();i++){
        imap[inorder[i]]=i;
    }
    TreeNode<int> * root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,imap);
    return root;
}



int main(){

    

    return 0;
}
