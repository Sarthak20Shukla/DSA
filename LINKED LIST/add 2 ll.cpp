//add 2 ll
#include<bits/stdc++.h>

using namespace std;

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node* t1=num1;
    Node* t2=num2;
    Node* dummynode=new Node(-1);
    Node* curr=dummynode;
    int carry=0;
    while(t1!=NULL||t2!=NULL){
        int sum=carry;

        if(t1) sum+=(t1->data);
        if(t2) sum+=(t2->data);
        Node* newNode=new Node(sum%10);
        carry=sum/10;
        curr->next=newNode;
        curr=curr->next;
        if(t1) t1=t1->next;
        if(t2) t2=t2->next;

    }
    if(carry){
        Node* newNode=new Node(carry);
        curr->next=newNode;
    }
    return dummynode->next;

}



int main(){

    

    return 0;
}
