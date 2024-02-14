//Rotate a ll by k times
#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
 Node *findkthnode(Node *temp, int k){
      int cnt=1;
      while(temp!=NULL){
           if(k==cnt) return temp;
           cnt++;
           temp=temp->next;
      }
      return temp;
 }

Node *rotate(Node *head, int k) {
     // Write your code here.
     int l=1;
     Node* tail=head;
     while(tail->next!=NULL){
          l++;
          tail=tail->next;
     }
     if(k%l==0) return head;
     k=k%l;
     tail->next=head;
     Node* temp=findkthnode(head,l-k);
     head=temp->next;
     temp->next=NULL;



     return head;
}

int main(){

    

    return 0;
}
