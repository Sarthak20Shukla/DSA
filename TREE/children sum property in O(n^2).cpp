//children sum property in O(n^2)
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
void check(Node* root,bool &b){
    if(root==NULL||(!root->left&&!root->right)) return;
    int l=0,r=0;
    if(root->left) l=root->left->data;
    if(root->right) r=root->right->data;
    if(root->data==l+r){
        check(root->left,b);
        check(root->right,b);
    }
    else b=false;
}

bool isParentSum(Node *root){
    // Write your code here.
    bool b=true;
    check(root,b);
    return b;
}

int main(){

    

    return 0;
}
