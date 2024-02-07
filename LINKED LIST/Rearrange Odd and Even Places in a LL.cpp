//Rearrange Odd and Even Places in a LL
#include<bits/stdc++.h>

using namespace std;
/****************************************************************
Following is the Linked list node structure already written

class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    { 
        this->data = data;
        next = NULL;
    }
};
*****************************************************************/

Node* oddEvenList(Node* head)
{
	// Write your code here.
    if(head==NULL || head->next==NULL) return head;
    Node* even=head->next;
    Node* odd=head;
    Node* evenhead=even;
    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;
        even->next=even->next->next;

        odd=odd->next;
        even=even->next;

    }
    odd->next=evenhead;
    return head;

}

int main(){

    

    return 0;
}
