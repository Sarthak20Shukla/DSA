//isPalindrome of a linked list
#include<bits/stdc++.h>

using namespace std;

/****************************************************************

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

*****************************************************************/
Node* reverse(Node *head)
{
    // Write your code here
    if (head == NULL || head->next == NULL) {
        return head; 
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;

    }
    return prev;

}

bool isPalindrome(Node *head)
{
    // write your code here
    if(head==NULL||head->next==NULL) return true;
    Node* fast=head;
    Node* slow=head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newnode=reverse(slow->next);
    Node* first=head;
    Node* second=newnode;
    while(second!=NULL){
        if(first->data!=second->data){
            reverse(newnode);
            return false;
        }
        first=first->next;
        second=second->next;
    }

    reverse(newnode);
    return true;
}

int main(){

    

    return 0;
}
