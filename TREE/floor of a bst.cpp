//floor of a bst
#include<bits/stdc++.h>

using namespace std;

int Floor(BinaryTreeNode<int> *node, int input)
{
		/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 
	int floor=-1;
	while(node){
		if(input==node->data){
			floor=node->data;
			return floor;
		}
		if(input>node->data){

			floor=node->data;
			node=node->right;
		}
		else{
			node=node->left;
		}
	}
	return floor;
}


int main(){

    

    return 0;
}
