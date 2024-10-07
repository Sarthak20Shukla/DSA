#include<bits/stdc++.h>

using namespace std;
int factorial(int n){
    int sum=1;
    for(int i=n;i>=1;i--){
        
            sum*=i;
        
    }
    return sum;
}

int main(){
    int sum=0;
    vector<int> v1;
    vector<int> q;
    string s;
    
    getline(cin,s);
    
    int token;
    istringstream ss(s);
    while(ss>>token){
        
        v1.push_back(token);

    }

    for(int i=0;i<v1.size();i++){
        int temp=v1[i];
        sum=0;
        while(temp){
            int num=temp%10;
            sum+=factorial(num);
            temp/=10;
        }
        if(v1[i]==sum) {
            q.push_back(v1[i]);
        }
    }
  for(int i=0;i<q.size()-1;i++){
    cout<<q[i]<<", ";
  }
  cout<<q[q.size()-1];
    cout<<endl;

    return 0;
}
