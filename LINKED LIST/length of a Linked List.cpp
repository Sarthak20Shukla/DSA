//length of a Linked List
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

int length(Node *head)
{
	//Write your code here
Node* temp=head;
int cnt=1;
while(temp->next!=NULL){
    cnt++;
    temp=temp->next;
}

    return cnt;
}

int main(){

    

    return 0;
}
