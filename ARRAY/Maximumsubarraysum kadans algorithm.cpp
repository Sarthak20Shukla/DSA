#include<bits/stdc++.h>

using namespace std;
long long maxSubarraySumbruteforce(vector<int> arr, int n)
{
    // Write your code here.
    long long sum,maxi=LONG_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum=0;
            for(int k=i;k<j;k++){
                sum+=arr[k];
                maxi=max(sum,maxi);
            }
        }
    }
    return maxi;
}
long long maxSubarraySumbetter(vector<int> arr, int n)
{
    // Write your code here.
    long long sum,maxi=LONG_MIN;
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++){
                sum+=arr[j];
                maxi=max(sum,maxi);
        }
    }
    return maxi;
}
long long maxSubarraySumoptimal(vector<int> arr, int n)
{
    // Write your code here.
    long long sum=0,maxi=LONG_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    if(maxi<0) maxi=0;
    return maxi;
}
int main(){

    

    return 0;
}
