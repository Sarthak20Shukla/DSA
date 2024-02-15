// Design Browser History
#include<bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>
using namespace std;

 

class Node{

    public:

    string data;

    Node * next;

    Node * prev;

 

    Node(string & val){

        data = val;

        next = nullptr;

        prev = nullptr;

    }

 

    Node(string &val, Node * next1 , Node * prev1){

        data = val;

        next = next1;

        prev = prev1;

    }

 

};
class Browser
{
    public:
    Node* current;
    Browser(string &homepage)
    {
        // Write you code here
        current=new Node(homepage);
    }

    void visit(string &url)
    {
        // Write you code here
        Node* newNode=new Node(url);
        current->next=newNode;
        newNode->prev=current;
        current=newNode;
    }

    string back(int steps)
    {
        // Write you code here
        while(steps){
          if (current->prev) {
            current = current->prev;
            steps--;
          } else
            break;
          
        }
        return current->data;
    }

    string forward(int steps)
    {
        // Write you code here
           while(steps){
          if (current->next) {
            current = current->next;
            steps--;
          } else
            break;
        }
        return current->data;
    }
};


int main(){

    

    return 0;
}
