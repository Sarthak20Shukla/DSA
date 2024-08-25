#include<bits/stdc++.h>

using namespace std;
void uttarBBrahma(int noSala,vector<int> &Arrayofturtle){
sort(Arrayofturtle.begin(),Arrayofturtle.end());
    cout<<Arrayofturtle[noSala/2 ]<<endl;
}
int main(){
int testSSHHtIVAYA;
cin>>testSSHHtIVAYA;
while(testSSHHtIVAYA--){
    int noSala;
    cin>>noSala;
    vector<int> Arrayofturtle(noSala);
    for(int i=0;i<noSala;i++){
        cin>>Arrayofturtle[i];
    }
    uttarBBrahma(noSala,Arrayofturtle);

}
    

    return 0;
}
