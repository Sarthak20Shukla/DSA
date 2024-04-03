//merge 2 bst
#include<bits/stdc++.h>

using namespace std;
/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
void inorder(TreeNode* root,vector<int> &in){
if(!root) return;
inorder(root->left, in);
in.push_back(root->data);
inorder(root->right, in);
}
vector<int> mergeSortedList(vector<int> a1,vector<int>a2){
    int i=0,j=0;
    vector<int>ans;
    while(i<a1.size() && j<a2.size()){
        if(a1[i]<a2[j]) ans.push_back(a1[i++]);
        else ans.push_back(a2[j++]);
    }
    while(i<a1.size()){
        ans.push_back(a1[i++]);
    }
      while(j<a2.size()){
        ans.push_back(a2[j++]);
    }
    return ans;
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int> in1;
    vector<int> in2;
    inorder(root1, in1);
    inorder(root2, in2);
    return mergeSortedList(in1,in2);
}

int main(){

    

    return 0;
}
