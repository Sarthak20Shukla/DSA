#include<iostream>
using namespace std;
int main(){
    int T,A,B,C,D;
    cin>>T;
    while(T--){
        cin>>A>>B;
        cin>>C>>D;
        if(C>=A && D>=B){
            cout<<"POSSIBLE"<<endl;

        } else{
            cout<<"IMPOSSIBLE"<<endl;
        }
    }
    return 0;
}