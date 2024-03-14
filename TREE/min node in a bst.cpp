//min node in a bst
#include<bits/stdc++.h>

using namespace std;

/*
 * class Node
 * {
 * public:
 *     int data;
 *     Node *left;
 *     Node *right;
 *     Node() : data(0), left(nullptr), right(nullptr){};
 *     Node(int x) : data(x), left(nullptr), right(nullptr) {}
 *     Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
 * };
 */
int minVal(Node* root){
	// Write your code here.
	int ans=0;
	Node* curr=root;
	if(curr==NULL) return -1;
	if(curr->left==NULL) return curr->data;
	while(curr!=NULL){
		ans=curr->data;
		curr=curr->left;
		
	}
	return ans;
}

int main(){

    

    return 0;
}
