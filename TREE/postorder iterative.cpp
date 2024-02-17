//postorder iterative 2 stack
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
vector<int> postorderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>postorder;
    stack<TreeNode *> a1,a2;
    a1.push(root);
    while(!a1.empty()){
        root=a1.top();
        a1.pop();
        a2.push(root);
        if(root->left) a1.push(root->left);
        if(root->right) a1.push(root->right);
        
    }
    while(!a2.empty()){
            postorder.push_back(a2.top()->data);
            a2.pop();
        }
    return postorder;
}

int main(){

    

    return 0;
}
