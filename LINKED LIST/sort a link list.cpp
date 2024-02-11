//sort a link list
#include<bits/stdc++.h>

using namespace std;

/*
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
*/

Node* sortList(Node* head){
    // Write your code here.
    if(head==NULL){
            return NULL;
        }
        vector<int>answer;

        Node *temp = head;
        while(temp!=NULL){
            answer.push_back(temp->data);
            temp=temp->next;
        }

        sort(answer.begin(),answer.end());
        
        int i=0;
        temp = head;
        while(temp!=NULL){
            temp->data = answer[i];  // change values in linked list
            i++;
            temp = temp->next;
        }

        return head;
}


int main(){

    

    return 0;
}
