#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
unordered_map<char,int> mp;
int main(){
int TEstVIshnuuurVasudev;
cin>>TEstVIshnuuurVasudev;
while(TEstVIshnuuurVasudev--){
    int noSalas;
    cin>>noSalas;
    string strng;
    cin>>strng;

    map<char,int> mppap;
    string Uttaraysn = "";

   for (int i = 0; i < strng.length(); i++) {
        mppap[strng[i]]++;
    }

    while (!mppap.empty()) {
        for (auto it = mppap.begin(); it != mppap.end(); ) {
            Uttaraysn += it->first;  
            it->second--;      

            if (it->second == 0) {
                it = mppap.erase(it);  
            } else {
                ++it;  
            }
        }
    }

    cout << Uttaraysn << endl;
    
}
    return 0;
}