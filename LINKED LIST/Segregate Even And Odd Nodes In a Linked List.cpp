// Segregate Even And Odd Nodes In a Linked List
#include<bits/stdc++.h>

using namespace std;

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 *		Node() : data(0), next(nullptr) {};
 *		Node(int x) : data(x), next(nullptr) {}
 *		Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* segregateEvenOdd(Node* head)
{
    // Write your code here
    Node* dummy1=new Node(0);
    Node* dummy2=new Node(0);
    Node* even=dummy1;
    Node* odd=dummy2;
    Node* temp=head;
    while(temp){
        if(temp->data %2 ==0){
            even->next=temp;
            even=even->next;
        } else{
            odd->next=temp;
            odd=odd->next;
        }
        temp=temp->next;
    }
    even->next=dummy2->next;
    odd->next=NULL;

    return dummy1->next;
}


int main(){

    

    return 0;
}
