//deleteNode at kth element
#include<bits/stdc++.h>

using namespace std;

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int val;
 *		Node *next;
 * 		Node *prev;
 *		Node() : val(0), next(nullptr), prev(nullptr){};
 *		Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *		Node(int x, Node *next, Node *prev) : val(x), next(next), prev(prev) {}
 * };
 */
Node * deletehead(Node *head) {
    // Write your code here.
    if(head==NULL|| head->next==NULL) return NULL;
    Node* pre=head;
    head=head->next;
    head->prev=NULL;
    pre->next=NULL;

    free(pre);
    return head;
}
Node * deletetail(Node *head) {
    // Write your code here.
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
Node *deleteNode(Node *head, int k){
    // Write your code here
    Node* temp=head;
    int cnt=0;
    while(temp!= NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;

    }
   Node* pre=temp->prev;
    Node* front=temp->next;
    if(pre==NULL&&front==NULL){free(temp); return NULL; }
    else if (pre==NULL) return deletehead(head);
    else if(front==NULL) return deletetail(head);
    else{
        pre->next=front;
        front->prev=pre;

        temp->next=NULL;
        temp->prev=NULL;
        free(temp);
    }
    return head;
}

int main(){

    

    return 0;
}
