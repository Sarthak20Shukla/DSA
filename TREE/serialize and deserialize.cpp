//serialize and deserialize
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

string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
 if(root==NULL) return " ";
 string s="";
 queue<TreeNode<int>*> q;
 q.push(root);
 while(!q.empty()){
     TreeNode<int>* curr=q.front();
     q.pop();
     if(curr==NULL) s.append("#,");
     else s.append(to_string(curr->data)+",");
     if(curr!=NULL){
         q.push(curr->left);
         q.push(curr->right);
     }

 }
 return s;

}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
if(serialized.size()==0) return NULL;
stringstream s(serialized);
string str;
getline(s,str,',');
TreeNode<int>* root= new TreeNode(stoi(str));
queue<TreeNode<int>*> q;
q.push(root);
while(!q.empty()){
    TreeNode<int>* node=q.front();
    q.pop();
    getline(s,str,',');
    if(str=="#") node->left=NULL;
    else{
        TreeNode<int>* leftNode=new TreeNode(stoi(str));
        node->left=leftNode;
        q.push(leftNode);
    }
    getline(s,str,',');
    if(str=="#") node->right=NULL;
    else{
        TreeNode<int>* rightNode=new TreeNode(stoi(str));
        node->right=rightNode;
        q.push(rightNode);
    }

}
return root;

}





int main(){

    

    return 0;
}
