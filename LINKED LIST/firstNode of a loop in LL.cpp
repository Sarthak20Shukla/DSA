//firstNode of a loop in LL
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

Node *firstNode(Node *head)
{
    //    Write your code here.
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;

            }
            return slow;
        }
    }
    return NULL;
}

int main(){

    

    return 0;
}
