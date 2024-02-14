//flattenLinkedList
#include<bits/stdc++.h>

using namespace std;

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
 Node* merge(Node* t1, Node* t2)
{
    // Write your code here.
	    if(t1->data <= t2->data) t2->next = nullptr;

    else t1->next = nullptr;
    Node* dNode=new Node(-1);
    Node* temp=dNode;
    while(t1!=NULL && t2!=NULL){
        if(t1->data<t2->data){
            temp->child=t1;
            temp=t1;
            t1=t1->child;
        } else {
            temp->child=t2;
            temp=t2;
            t2=t2->child;
        }
		temp->next=NULL;
    }
    if(t1) temp->child=t1;
    else temp->child=t2;
	if(dNode->child) dNode->child->next=NULL;
    return dNode->child;
}


Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(head==NULL ||head->next==NULL) return head;
	head->next=flattenLinkedList(head->next);
	head=merge(head,head->next);
	return head;
	
}


int main(){

    

    return 0;
}
