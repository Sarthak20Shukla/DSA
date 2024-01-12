//majorityElement(>n/2)
#include<bits/stdc++.h>

using namespace std;
int majorityElementbruteforce(vector<int> v) {
	// Write your code here
	for(int i=0;i<v.size();i++){
	int cnt=0;
    for(int j=;j<n;j++){
    if(v[j]==v[i]){
        cnt++;
    }
    }
    if(cnt>n/2) return v[i];
    }
}

int majorityElementbetter(vector<int> v) {
	// Write your code here
	map<int,int>mpp;
	for(int i=0;i<v.size();i++){
		mpp[v[i]]++;
	}
	for(auto it:mpp){
		if(it.second>(v.size()/2)){
			return it.first;
		}
	}
	return -1;

}
int majorityElementoptimal(vector<int> v) {
	// Write your code here
	int cnt=0,el;
    for(int i=0;i<n;i++){
    if(cnt==0){
        cnt=1;
        el=v[i];
    } else if(v[i]==el){
        cnt++;
    }
    else cnt--;
    }
    int cnt1=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==el) cnt1++;
    }
    if(cnt1>(v.size()/2)){
        return el;
    }
	return -1;

}

int main(){

    

    return 0;
}
