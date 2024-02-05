//deletion of a node from ll
#include<bits/stdc++.h>

using namespace std;
/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *deleteLast(Node *head){
    // Write your code here
    Node* temp=head;
    if(head==NULL||head->next==NULL) return NULL;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;


    return head;

}

int main(){

    

    return 0;
}
