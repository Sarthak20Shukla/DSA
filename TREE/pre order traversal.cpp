//pre order traversal
#include<bits/stdc++.h>

using namespace std;

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
 vector<int> res;
 void preOrder2(TreeNode<int> * root){
      if(root== NULL) return;
    res.push_back(root->data);
    preOrder2(root->left);
    preOrder2(root->right);
 }
vector<int> preOrder(TreeNode<int> * root){
    // Write your code here.
   
   preOrder2(root);

    return res;

}


int main(){

    

    return 0;
}
