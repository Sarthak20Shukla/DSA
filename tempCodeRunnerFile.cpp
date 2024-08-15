#include<bits/stdc++.h>
using namespace std;

const int NUMBER = 2e5 + 10;
int ScoreSJFJ[NUMBER];

void solve(int number,int kK) {
	
	long long uttar = 0;
	sort(ScoreSJFJ+1, ScoreSJFJ+ number+1, greater<int>());
	for(int i=1;i<=number;i++) {
		if(i&1) {
			uttar+=ScoreSJFJ[i]; 
		} else {
			int d=min(kK,ScoreSJFJ[i-1] - ScoreSJFJ[i]);
			ScoreSJFJ[i]+=d;
			kK-=d;
			uttar-=ScoreSJFJ[i];
		}
	}

	cout <<uttar<< endl;
}

int main() {
	
	int TesTRREVRahma; 
	cin >> TesTRREVRahma;
	while(TesTRREVRahma--) {
		int number, kK; 
		cin >> number >> kK;
	for(int i = 1; i <= number; i++) 
		cin >> ScoreSJFJ[i];
		solve(number,kK);
	}	
	return 0;
}

