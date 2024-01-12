#include<bits/stdc++.h>

using namespace std;

int main(){

    int maxi=0,count=0;
    int m,n;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                count+=1;
                maxi=max(maxi,count);
            }
        }
        cout<<"max is"<<(maxi+m)<<endl;
    return 0;
}
