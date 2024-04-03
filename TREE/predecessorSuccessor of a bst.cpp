//predecessorSuccessor of a bst
#include<bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
using namespace std;
/*************************************************************

    Following is the Binary Tree node structure
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

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    int successor=-1;
    int predecessor=-1;
    TreeNode* temp=root;
    //finding successor
    while(temp!=NULL){
        if(key>=temp->data) temp=temp->right;
        else{
            successor=temp->data;
            temp=temp->left;
        }
    }
      temp=root;
      //finding predecessor
    while(temp!=NULL){
        if (key <= temp->data) {
            
            temp = temp->left;
            
        } else {
            predecessor=temp->data;
            temp=temp->right;
        }
    }
    pair<int, int> ans = {predecessor, successor};
    return ans;
}

int main(){

    

    return 0;
}
