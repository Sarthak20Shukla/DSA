//reverseLinkedListrecursive
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

Node* reverseLinkedListrecursive(Node *head)
{
    // Write your code here
    if(head==NULL||head->next==NULL){ return head; }
    Node* newHead=reverseLinkedList(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;

}


int main(){

    

    return 0;
}
