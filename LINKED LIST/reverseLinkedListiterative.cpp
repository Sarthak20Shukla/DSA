//reverseLinkedListiterative
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

Node* reverseLinkedListOptimal(Node *head)
{
    // Write your code here
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


int main(){

    

    return 0;
}
