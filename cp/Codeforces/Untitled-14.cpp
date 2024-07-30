#include<bits/stdc++.h>

using namespace std;

int main(){

    int TesTCasEsShiV;
    cin>>TesTCasEsShiV;
    while(TesTCasEsShiV--){
        int numBER;
        cin>>numBER;
         vector<string> strg(2);
        cin>>strg[0]>>strg[1];

        int uttar=0;
        for(int i=0;i<2;i++){
            for(int j=1;j<numBER-1;j++){
                if(strg[i][j] == '.' && strg[(i+1)%2][j] == '.' && strg[i][j-1] == '.' && strg[i][j+1] == '.'){
                     if(strg[(i+1)%2][j-1] == 'x' && strg[(i+1)%2][j+1] == 'x') uttar++;
                }
            }
        }
        cout<<uttar<<endl;
    }

    return 0;
}
