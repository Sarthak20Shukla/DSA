#include<iostream>
using namespace std;
int main(){
    int T,X,Y,Z;
    cin>>T;
    while(T--){
        cin>>X>>Y>>Z;
     int value=Z-(Y/X);
     if(value<<0){
         int val=-(value);
     }
     cout<<value<<endl;
}
    return 0;
}