#include<bits/stdc++.h>

using namespace std;

int main(){

    priority_queue<int> pq;
    int i;
    cin>>i;
    while(i--){
        int x;
        cin>>x;
        pq.push(x);
    }
     for(int it:pq){
        cout<<it<<" ";
     }
     cout<<endl;

    return 0;
}
