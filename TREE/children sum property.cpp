//children sum property O(n)
#include<bits/stdc++.h>

using namespace std;

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

bool isParentSum(Node *root){
    // Write your code here.
    if(root==NULL) return;
    int child = 0;
    if(root->left) child+=root->left->data;
    if(root->right) child+=root->right->data;
    if(child>=root->data) root->data=child;
    else{
        if(root->left) root->left->data=root->data;
        else if(root->right) root->right->data=root->data;
    }
    isParentSum(root->left);
    isParentSum(root->right);
    int tot=0;
    if(root->left) tot+=root->left->data;
    if(root->right) tot+=root->right->data;
    if(root->left || root->right) root->data=tot;


}

int main(){

    

    return 0;
}
