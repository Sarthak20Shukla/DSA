#include<iostream>
using namespace std;
int main(){
    int n,t;
    cin>>n;
    
    while(n--)
    {
      cout<<"enter time"<<endl;
      cin>>t;
        if(t>=1&&t<=4){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
        

    }
    return 0;
}