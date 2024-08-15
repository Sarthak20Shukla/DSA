#include<bits/stdc++.h>
using namespace std;

void solve(int leftbound,int rightbound,int LEFTBOUND,int RIGHTBOUND,vector<int> &dppp) {
	
	int x = min(rightbound, RIGHTBOUND) - max(leftbound, LEFTBOUND);
	if(leftbound < LEFTBOUND) dppp[LEFTBOUND - 1] = 1;
	if(LEFTBOUND < leftbound) dppp[leftbound - 1] = 1;
	if(RIGHTBOUND > rightbound) dppp[rightbound] = 1;
	if(rightbound > RIGHTBOUND) dppp[RIGHTBOUND] = 1;

	int uttar = 0;
	for(int i = 1; i <= 101; i++) {
		uttar += dppp[i];
	}

	if(x < 0) uttar = 0;
	cout << max(1, uttar + x) << endl;
}

int main() {
	
	int TestSHIV; 
	cin >> TestSHIV;
	while(TestSHIV--) {
int leftbound, rightbound; 
	int LEFTBOUND, RIGHTBOUND;

cin >> leftbound >> rightbound;
	 cin >> LEFTBOUND >> RIGHTBOUND;
	vector<int> dppp(105, 0);
		solve(leftbound,rightbound,LEFTBOUND,RIGHTBOUND,dppp);
	}	
}
