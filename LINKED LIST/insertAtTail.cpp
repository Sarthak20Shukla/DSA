//insertAtTail(AFTER) in dll
#include<bits/stdc++.h>

using namespace std;

/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int value;
 *      Node *prev;
 *      Node *next;
 *      Node() : value(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : value(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : value(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/
Node* insertAtFront(Node *head, int k) {
    // Write your code here.
    Node* newHead=new Node(k,nullptr,head);
    if(head==NULL) return newHead;
    
    head->prev=newHead;
    return newHead;
}
Node * insertAtTail(Node *head, int k) {
    // Write your code here
    
    Node* newHead=new Node(k);
    if(head==NULL) return newHead;
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    
    tail->next=newHead;
    newHead->prev=tail;

    return head;

}


int main(){

    

    return 0;
}
