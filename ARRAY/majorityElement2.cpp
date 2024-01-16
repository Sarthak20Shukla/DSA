//Majority element2 n/3
#include<bits/stdc++.h>

using namespace std;


vector<int> majorityElementoptimal(vector<int> v) {
	// Write your code here
    int cnt1=0,cnt2=0;
    int el1=INT_MIN,el2=INT_MIN;
    for(int i=0;i<n;i++){
        if(cnt1==0&&v[i]!=el2){
            cnt1++;
            el1=v[i];

        }
        else if(cnt2==0&&v[i]!=el1){
            cnt2++;
            el2=v[i];
        }
        else if(v[i]==el1){
            cnt1++;
        }
        else if(v[i]==el2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }

    }
	vector<int> ls;
    int cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(v[i]==el1) cnt1++;
        if(v[i]==el2) cnt2++;
    }
    int mm=int(n/3)+1;
    if(cnt1>=mm) ls.push_back(el1);
    if(cnt2>=mm) ls.push_back(el2);
	return ls;
}
vector<int> majorityElementbetter(vector<int> v) {
	// Write your code here
	vector<int> ls;
	unordered_map<int,int> mpp;
	int mm=int(v.size()/3)+1;
	for(int i=0;i<v.size();i++){
		mpp[v[i]]++;
		if(mpp[v[i]]==mm){
			ls.push_back(v[i]);
		}
		if(ls.size()==2) break;
		
	}
	sort(ls.begin(),ls.end());
	return ls;
}
vector<int> majorityElementbrute(vector<int> v) {
	// Write your code here
	vector<int> ls;
	for(int i=0;i<v.size();i++){
		if(ls.size()==0||ls[0]!=v[i]){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(v[j]==v[i]) cnt++;
                if(cnt>n/3) ls.add(v[i]);
            }
        }
        if(ls.size()==2) break;
		
	}
	sort(ls.begin(),ls.end());
	return ls;
}

int main(){

    

    return 0;
}
