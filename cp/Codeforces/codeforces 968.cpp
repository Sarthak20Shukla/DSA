#include<bits/stdc++.h>

using namespace std;
bool isgoodString(string s){
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != s[i]) {
            string t1 = s.substr(0, i);
            string t2 = s.substr(i);
            if (t1[0] != t2[t2.size() - 1]) {
                return true;
            }
        }
    }
    return false;
}
int main(){

    int t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(isgoodString(s) == true) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        }

    return 0;
}
