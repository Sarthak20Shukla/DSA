//getLongestSubarraywith sum k
#include<bits/stdc++.h>

using namespace std;
int getLongestSubarraybruteforce(vector<int> a, long long k) {
    // Write your code here
    int n=a.size();int length=0;
        for(int i=0;i<n;i++){
        long long sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            if(sum==k){
                length=max(length,j-i+1);
            }
        }
    }
    return length;
}
int getLongestSubarraybetter(vector<int> a, long long k) {
    // Write your code here
    long long s=0;long long rem;
    int maxlen=0;
    map<long long,int> presummap;
    
    for(int i=0;i<a.size();i++){
       s+=a[i];
        if(s==k){
            maxlen=max(maxlen,i+1);
        }
        rem=s-k;
        if(presummap.find(rem)!=presummap.end()){
            int len=i-presummap[rem];
            maxlen=max(len,maxlen);
        }
         if(presummap.find(s)==presummap.end()){
            presummap[s]=i;
         }
    }
    return maxlen;
}
int getLongestSubarrayoptimal(vector<int> a, long long k) {
    // Write your code here
    int l=0,r=0;int n=a.size();
    int maxlen=0;long long sum=a[0];
    while(r<n){
        while(l<=r && sum>k){
            sum-=a[l++];
        }
        if(sum==k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
        if(r<n) sum+=a[r];
    }
    return maxlen;
}

int main(){
    vector<int> a = {2,3,5,1,9};
    long long k = 10;
    int len = getLongestSubarraybruteforce(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}
