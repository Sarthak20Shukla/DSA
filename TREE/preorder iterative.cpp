//preorder iterative
#include<bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>
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

vector<int> preOrder(TreeNode<int> * root){
    // Write your code here.
    vector<int> preorder;
    if(root==NULL) return preorder;
    stack<TreeNode<int>*> st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        preorder.push_back(root->data);
        if(root->right != NULL) st.push(root->right);
        if(root->left != NULL) st.push(root->left);
    }
    return preorder;
}


int main(){

    

    return 0;
}
