//flatten binary tree using stack
#include<bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void flattenBinaryTree(TreeNode<int>* root)
{
    // Write your code here.
    stack<TreeNode<int>*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode<int>* curr=st.top();
        st.pop();
        if(curr->right){
            st.push(curr->right);

        }
        if(curr->left){
            st.push(curr->left);
            
        }
        if(!st.empty()){
            curr->right=st.top();

        }
        curr->left=NULL;

    }
}

int main(){

    

    return 0;
}
