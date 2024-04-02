//validate a bst
#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }
    bool isValidBST(TreeNode* root, long min_value,long max_value) {
        if(root==NULL) return true;
        if(root->val>=max_value || root->val<=min_value) return false;
        return (isValidBST(root->left,min_value,root->val) && isValidBST(root->right,root->val,max_value));
    }
};

int main(){

    

    return 0;
}
