#include<bits/stdc++.h>

using namespace std;

int main(){

    string s;
    getline(cin,s);
    int num;
    vector<int> v;
    stringstream ss(s);
    while(ss>>num){
        v.push_back(num); 
    }
    for(auto it: v){
        cout<<it<<" ";
    }

    return 0;
}
