//morris traversal inorder
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

vector<int> inorder(TreeNode<int> * root){
    // Write your code here.
    vector<int> inorder;
        TreeNode<int>* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->data);
                curr=curr->right;
            }else{
                TreeNode<int>* prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    inorder.push_back(curr->data);
                    curr=curr->left;
                }else {
                    prev->right=NULL;
                    
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }


int main(){

    

    return 0;
}
