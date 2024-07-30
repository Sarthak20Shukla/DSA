#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int x;
	    cin>>x;
	    if((x & (x-1))==0) return 0;
	    int lpof2=1;
	    while(lpof2*2 <x){
	        lpof2*=2;
	    }
	    cout<<(x-lpof2)*2<<endl;
	}
	return 0;
}