//deleteLastNode of a DLL
#include<bits/stdc++.h>

using namespace std;

/**
 * Definition of doubly linked list:
 *
 * struct Node {
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() : data(0), prev(nullptr), next(nullptr) {}
 *      Node(int val) : data(val), prev(nullptr), next(nullptr) {}
 *      Node(int val, Node *p, Node *n) : data(val), prev(p), next(n) {}
 * };
 *
 *************************************************************************/

Node * deleteLastNode(Node *head) {
    // Write your code here
     if(head==NULL|| head->next==NULL) return NULL;
  Node* tail=head;
   while(tail->next!=NULL){
       tail=tail->next;

   }
   Node* pre=tail->prev;
   pre->next=nullptr;
   tail->prev=nullptr;
    return head;
}


int main(){

    

    return 0;
}
