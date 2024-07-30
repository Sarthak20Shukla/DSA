#include<bits/stdc++.h>

using namespace std;
int Sammyaanusandhan(string &s){
    int samaya=2;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1]) samaya+=1;
        else samaya+=2;
    }
    return samaya;
}
int main(){

    int tEsTCases;
    cin>>tEsTCases;
    while(tEsTCases--){
        string s;
        cin>>s;
        int n=s.length();
        int atyadhiksamay=-1;
        string badhiapassword;
        for(int i=0;i<=n;i++){
            for(char ch='a';ch<='z';ch++){
                string npassw=s.substr(0,i)+ch+s.substr(i);
                int newSamay=Sammyaanusandhan(npassw);
                if(atyadhiksamay<newSamay){
                    atyadhiksamay=newSamay;
                    badhiapassword=npassw;
                }
            }
        }
        cout<<badhiapassword<<endl;
    }

    return 0;
}
