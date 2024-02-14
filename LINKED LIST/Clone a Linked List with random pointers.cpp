// Clone a Linked List with random pointers

#include<bits/stdc++.h>

using namespace std;

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *random;
 *		Node() : data(0), next(nullptr), random(nullptr){};
 *		Node(int x) : data(x), next(nullptr), random(nullptr) {}
 *		Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
 * };
 */

Node *cloneLL(Node *head){
	// Write your code here
	     Node* temp = head;
	//step 1
    while(temp != NULL) {
        Node* newNode = new Node(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
	//step 2
    Node* itr = head;
    while(itr != NULL) {
        if(itr->random != NULL)
            itr->next->random = itr->random->next;
        itr = itr->next->next;
    }
	//step 3
    Node* dummy = new Node(0);
    itr = head;
    temp = dummy;
    Node* fast;
    while(itr != NULL) {
        fast = itr->next->next;
        temp->next = itr->next;
        itr->next = fast;
        temp = temp->next;
        itr = fast;
    }
    return dummy->next;
}

int main(){

    

    return 0;
}
