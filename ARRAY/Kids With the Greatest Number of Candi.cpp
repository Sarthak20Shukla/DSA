//Kids With the Greatest Number of Candies//
#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n,extracandies;
    cin>>n>>extracandies;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxcandies=INT_MIN;
    for(int i=0;i<n;i++){
        maxcandies=max(maxcandies, arr[i]);
    } cout<<maxcandies<<endl;
    for(int i=0;i<n;i++){
        if((extracandies+arr[i])<maxcandies){
            cout<<"F";
        }
        if((extracandies+arr[i])>=maxcandies){
            cout<<"T";
        }
    }

    return 0;
}