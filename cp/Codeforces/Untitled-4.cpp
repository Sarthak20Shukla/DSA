#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    int cnt=0;
    cin>>n;
    while(n!=0){
        if(n%2==0){
            n=n/2;
            cnt++;
        } else{
            n=n-1;
            cnt++;
        }

    }
    cout<<cnt;

    return 0;
}
