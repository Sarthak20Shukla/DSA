//levelOrder traversal
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

vector<int> levelOrder(TreeNode<int> * root){
    // Write your code here.
   vector<int >ans;

    if(root==NULL)return ans;

    queue<TreeNode<int> *>q;

    q.push(root);

    while(!q.empty()){

       TreeNode<int> * curr=q.front();

        q.pop();

        if(curr->left!=NULL)q.push(curr->left);

        if(curr->right!=NULL)q.push(curr->right);

        ans.push_back(curr->data);

    }

    return ans;
}


int main(){

    

    return 0;
}
