#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;


    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end(),greater<int>());

    for(int i=1;i<n;i++){
        if(arr[i] != arr[0]) {cout<<arr[i]<<endl;
            break;
        }
        else {cout<<"No sec largest"<<endl;
            break;
        }
    }


    return 0;
}
