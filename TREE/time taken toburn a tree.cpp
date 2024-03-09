#include<bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
BinaryTreeNode<int>* mark_parents(BinaryTreeNode<int>* root,map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &mapp,int start){
    queue<BinaryTreeNode<int>*> queue;
    BinaryTreeNode<int>* res;
    queue.push(root);
    while(!queue.empty()){
        BinaryTreeNode<int>* current=queue.front();
        if(current->data==start){
            res= current;
        }
        queue.pop();
        if(current->left){
            queue.push(current->left);
            mapp[current->left]=current;
        }
        if(current->right){
            queue.push(current->right);
            mapp[current->right]=current;
        }
    }
    return res;

}
 
int burn(map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &mapp,BinaryTreeNode<int>* target){
    
    queue<BinaryTreeNode<int>*> queue;
    map<BinaryTreeNode<int>*,int> visited;
    queue.push(target);
    visited[target]=1;
    int level=0;
    
    while(!queue.empty()){
        int size=queue.size();
        int f=0;
        
        for(int i=0;i<size;i++){
            auto current=queue.front();
            queue.pop();
            if(current->left && !visited[current->left]){
                f=1;
                queue.push(current->left);
                visited[current->left]=1;
                
            } 
            if(current->right && !visited[current->right])
            {
                f=1;
                queue.push(current->right);
                visited[current->right]=1;
                 
            }
            if(mapp[current] && !visited[mapp[current]])
            {
                f=1;
                queue.push(mapp[current]);
                visited[mapp[current]]=1;
                 
            }
        }
        if(f) level++;

    }
    return level;
} 
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
   /*
*/
 map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> mapp;
 BinaryTreeNode<int>* target=mark_parents(root,mapp,start);
 int level=burn(mapp,target);
 return level;


}


int main(){

    

    return 0;
}
