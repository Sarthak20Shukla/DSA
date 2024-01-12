#include<bits/stdc++.h>

using namespace std;
void frequency(int arr[],int n){
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        map[arr[i]]++;
    }
    int maxfreq=0,maxele=0,minfreq=n,minele=0;
    for(auto it:map){
        int count=it.second;
        int element=it.first;
        if(count>maxfreq){
            maxele=element;
            maxfreq=count;
        }
        if(count<minfreq){
            minele=element;
            minfreq=count;
        }
    }
    cout<<"Max freq element is "<<maxele<<endl;
    cout<<"Min freq element is "<<minele<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // int arr[6]={2,4,9,0,9,5};
    // int n=sizeof(arr)/sizeof(arr[0]);
    frequency(arr,n);

    return 0;
}
