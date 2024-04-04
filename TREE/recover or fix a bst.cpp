//recover or fix a bst
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
  
    class Solution {
    public:

    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
public:
Solution(){
 prev=new TreeNode(INT_MIN);
 first=NULL;
prev=NULL;middle=NULL;
last=NULL;
}
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev!=NULL && prev->data>root->data){
          if (first == NULL) {
            first = prev;
            middle = root;
          } else
            last = root;
        }
        prev = root;

        inorder(root->right);
    }
    } ;
    TreeNode *FixBST(TreeNode *root) {
    // Write your code here.

        Solution s1=Solution();
        s1.inorder(root);
        if(s1.first && s1.last) swap(s1.first->data,s1.last->data);
        else if(s1.first && s1.middle) swap(s1.first->data,s1.middle->data);
    }

int main(){

    

    return 0;
}
