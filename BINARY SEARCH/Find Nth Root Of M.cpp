//Find Nth Root Of M
#include<bits/stdc++.h>

using namespace std;
int pow(int mid,int n,int m){
  long long ans=1;
  for(int i=1;i<=n;i++){
    ans*=mid;
    if(ans>m) return 2;
  }
  if(ans==m) return 1;
  else return 0;
}
int NthRoot(int n, int m) {
  // Write your code here.
  int low=1,high=m;
  while(low<=high){
    int mid=(high+low)/2;
    if(pow(mid,n,m)==1) return mid;
    else if(pow(mid,n,m)==0) low=mid+1;
    else high=mid-1;
  }
  return -1;
}

int main(){

    

    return 0;
}
