#include<bits/stdc++.h>

using namespace std;

int main(){

   int t;
    cin>>t;
    while(t--){
         int n;
        cin>>n;
        int cnt2legs=0;
        int cnt4legs=0;
        if(n%2==0){
            while(n!=0){
            if(n>=4){
                n=n-4;
                cnt4legs++;
            }
            if(n==2){
                n=n-2;
                cnt2legs++;
            }
        }
        }
        cout<<cnt2legs+cnt4legs<<endl;
    }

    return 0;
}
