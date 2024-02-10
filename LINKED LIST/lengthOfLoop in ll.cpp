//lengthOfLoop in ll
#include<bits/stdc++.h>

using namespace std;

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/
int length(Node *slow,Node *fast){
    int cnt=1;
    fast=fast->next;
    while(slow!=fast){
        cnt++;
        fast=fast->next;
    }
    return cnt;
}
int lengthOfLoop(Node *head) {
    // Write your code here
     Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return length(slow,fast);
    }
    return 0;
}


int main(){

    

    return 0;
}
