//delete an node from dll
#include<bits/stdc++.h>

using namespace std;

/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int val) {
            this->data = val;
            next = NULL;
            prev = NULL;
        }
    };

************************************************************/

void deleteNode(Node* temp) {
    //Write your code here.
    Node* pre=temp->prev;
    Node* front=temp->next;
    if(front==NULL){
        pre->next=nullptr;
        temp->prev=nullptr;
        free(temp);
        return;
    }
    pre->next=front;
        front->prev=pre;
        temp->next=temp->prev=NULL;
        
        free(temp);
}

int main(){

    

    return 0;
}
