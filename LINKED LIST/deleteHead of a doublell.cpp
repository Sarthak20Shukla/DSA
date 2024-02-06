//deleteHead of a doublell
#include<bits/stdc++.h>

using namespace std;


/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev=NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->next= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};
*/

Node * deleteHead(Node *head) {
    // Write your code here.
    if(head==NULL|| head->next==NULL) return NULL;
    Node* pre=head;
    head=head->next;
    head->prev=NULL;
    pre->next=NULL;

    free(pre);
    return head;
}

int main(){

    

    return 0;
}
