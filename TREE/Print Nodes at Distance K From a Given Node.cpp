//Print Nodes at Distance K From a Given Node
/*************************************************************

    Following is the Binary Tree node structure for reference:

    class BinaryTreeNode{
	public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void mark_parents(BinaryTreeNode<int>* root,unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &mapp,BinaryTreeNode<int>* target){
    queue<BinaryTreeNode<int>*> queue;
    queue.push(root);
    while(!queue.empty()){
        BinaryTreeNode<int>* current=queue.front();
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

}
vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int K) {
    // Write your code here.
    unordered_map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> mapp;
    mark_parents(root,mapp,target);
    queue<BinaryTreeNode<int>*> queue;
    unordered_map<BinaryTreeNode<int>*,bool>visited;
    queue.push(target);
    visited[target]=true;
    int level=0;
    while(!queue.empty()){
        int size=queue.size();
        if(level++ == K) break;
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>* current=queue.front();
    queue.pop();
            if(current->left&& !visited[current->left]){
                queue.push(current->left);
                visited[current->left]=true;
            }
            if(current->right&& !visited[current->right]){
                queue.push(current->right);
                visited[current->right]=true;
            }
            if(mapp[current]&& !visited[mapp[current]]){
                queue.push(mapp[current]);
                visited[mapp[current]]=true;
            }
        }
    }
vector<BinaryTreeNode<int>*> result;
while(!queue.empty()){
    BinaryTreeNode<int>* current=queue.front();
    queue.pop();
    result.push_back(current);
}
   return result;
}