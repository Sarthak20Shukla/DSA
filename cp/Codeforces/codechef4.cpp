#include<iostream>
using namespace std;
int main(){
    int T,X;
    cin>>T;
    while(T--){
        cin>>X;
     if(X%3==0){
       cout<<"normal"<<endl;
     } else if(X%3==1){
       cout<<"huge"<<endl;
     } else if(X%3==2){
       cout<<"small"<<endl;
     }
}
    return 0;
}