#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution{
 public :
 int widthOfBinaryTree(Node* root){
    int ans=0  ;
        if(!root) return ans;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            int mmin=q.front().second;
            int f,l;
            for(int i=0;i<n;i++){
                int curr=q.front().second-mmin;
                Node* node=q.front().first;
                q.pop();
                if(i==0) f=curr;
                if(i==n-1) l=curr;
                if(node->left){
                    q.push({node->left,2*curr+1});
                }if(node->right){
                    q.push({node->right,2*curr+2});
                }

            }
            ans=max(ans,l-f+1);
        }
        return ans;
 }

};


int main() {
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Solution sol;

    int maxWidth = sol.widthOfBinaryTree(root);

    cout << "Maximum width of the binary tree is: "<< maxWidth << endl;

    return 0;
}