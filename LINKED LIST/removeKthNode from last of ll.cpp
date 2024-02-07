//removeKthNode from last of ll
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

Node* removeKthNodeoptimal(Node* head, int K)
{
    // Write your code here.
    Node* fast=head;
    Node* slow=head;
    for(int i=0;i<K;i++) fast=fast->next;
    if(fast==NULL)return head->next;
    while(fast->next != NULL){
        fast=fast->next;
        slow=slow->next;
    }
    Node* delNode=slow->next;
    slow->next=slow->next->next;
    free(delNode);
    return head;

}


int main(){

    

    return 0;
}
