//MAX PATH SUM OF A BINARY TREE
#include<bits/stdc++.h>

using namespace std;

/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int height(BinaryTreeNode<int> *root,int &maxi){
    if(root==NULL) return 0;
    int left=max(0,height(root->left,maxi));
    int right=max(0,height(root->right,maxi));
    maxi=max(maxi,left+right+root->data);
    return root->data + max(left,right);


}
int maxPathSum(BinaryTreeNode<int> *root)
{
    // Write your code here
    int maxi=INT_MIN;
    height(root,maxi);
    return maxi;

}

int main(){

    

    return 0;
}
