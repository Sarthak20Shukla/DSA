#include<bits/stdc++.h>
//heap/ priority  queue
using namespace std;

int main(){

    priority_queue<int,vector<int>,greater<int>> pq;
    int i;
    cin>>i;
    while(i--){
        int x;
        cin>>x;
        pq.push(x);
    }
     
     cout<<pq.top()<<endl;

    return 0;
}
