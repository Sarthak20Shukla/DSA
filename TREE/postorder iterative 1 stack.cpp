//postorder iterative 1 stack
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
    vector<int> postorder;
    stack<TreeNode*> st;
    while(root!=NULL || ! st.empty()){
        if(root!=NULL){
            st.push(root);
            root=root->left;
        } else{
            TreeNode* temp=st.top()->right;
            if(temp==NULL){
                temp=st.top();
                st.pop();
                postorder.push_back(temp->data);
                while(!st.empty() && temp== st.top()->right){
                temp=st.top();
                st.pop();
                postorder.push_back(temp->data);
                }
            } else root=temp;
        }

    }
    return postorder;
}

int main(){

    

    return 0;
}
