//largest BST in a binary tree
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
class NodeValue{
    public:
    int minNode;
    int maxNode;
    int maxSize;
    NodeValue(int minNode,int maxNode,int maxSize){
        this->maxNode=maxNode;
        this->minNode=minNode;
        this->maxSize=maxSize;
    }
};
NodeValue largestBSThelper(TreeNode* root){
    if(root==NULL) return NodeValue(INT_MAX,INT_MIN,0);
    auto left=largestBSThelper(root->left);
    auto right=largestBSThelper(root->right);
    if(left.maxNode<root->data && right.minNode>root->data){
        return NodeValue(min(root->data,left.minNode),max(root->data,right.maxNode),left.maxSize+right.maxSize+1);
    }
    return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
}
int largestBST(TreeNode * root){
    // Write your code here.
    NodeValue ans=largestBSThelper(root);
    return ans.maxSize;
}

int main(){

    

    return 0;
}
