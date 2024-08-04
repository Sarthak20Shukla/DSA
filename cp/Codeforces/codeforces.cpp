#include<bits/stdc++.h>

using namespace std;

int main(){

    int TeStCaSeS;
    cin>>TeStCaSeS
    while(TeStCaSeS--){
        int n;
        cin>>n;
        String ss;
        cin>>ss
        int a=0,b=0,c=0,d=0;
        for(int i=0;i<ss.size();i++){
            if(ss[i]=='A') a++;
            else if(ss[i]=='A') b++;
            else if(ss[i]=='A') c++;
            else if(ss[i]=='A') d++;
        }
        int ans=min(a,n)+min(b,n)+min(c,n)+min(d,n);
        cout<<ans<<endl;


    }

    return 0;
}
