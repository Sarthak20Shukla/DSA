//deleteMiddle node of a ll
#include<bits/stdc++.h>

using namespace std;

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* deleteMiddle(Node* head){
    // Write your code here.
    if(head==NULL||head->next==NULL) return NULL;
    Node* slow=head;
    Node* fast=head;
    fast=fast->next->next;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* middle=slow->next;
    slow->next=slow->next->next;
    free(middle);

    return head;
}


int main(){

    

    return 0;
}
