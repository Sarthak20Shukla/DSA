// Reverse List In K Groups

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
 Node* reverseLinkedList(Node *head)
{
    // Write your code here
  Node* temp = head;  
   
   
   Node* prev = NULL;  
   while(temp != NULL){ 
       Node* front = temp->next;
       temp->next = prev;  
       prev = temp; 
       temp = front; 
   }
   return prev;  

}
Node* getKthNode(Node* temp, int k){

    k -= 1; 

    while(temp != NULL && k > 0){
        k--; 
        
        temp = temp -> next; 
    }
    
    return temp; 
}

Node* kReverse(Node* head, int k) {
    // Write your code here.
    Node* temp=head;
    Node* prevNode=NULL;
    while(temp!=NULL){
        Node* kthNode=getKthNode(temp,k);
        if(kthNode==NULL){
            if(prevNode) prevNode->next=temp;
            break;
        }
       Node* nextNode=kthNode->next;
        kthNode->next=NULL;
        reverseLinkedList(temp);
        if(temp==head){
            head=kthNode;
        } else prevNode->next=kthNode;
        prevNode=temp;
        temp=nextNode;
    }
    return head;
}

int main(){

    

    return 0;
}
