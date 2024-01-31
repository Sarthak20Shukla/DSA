//Minimise Maximum Distance between Gas Stations 
#include<bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>
long double minimiseMaxDistanceBetter(vector<int> &arr, int k){
	// Write your code here.	
	int n=arr.size();
	vector<int>howMany(n-1,0);
	priority_queue<pair<long double,int>>pq;
	for(int i=0;i<n-1;i++){
		pq.push({arr[i+1]-arr[i],i});
	}
	for(int gasStation=1;gasStation<=k;gasStation++){
		auto tp=pq.top();
		pq.pop();
		int secInd=tp.second;
		howMany[secInd]++;
		long double diff=arr[secInd+1]-arr[secInd];
		long double newS=diff/(long double)(howMany[secInd]+1);
		pq.push({newS,secInd});
	}
	return pq.top().first;
}



long double minimiseMaxDistancebruteforce(vector<int> &arr, int k) {
    int n = arr.size(); //size of array.
    vector<int> howMany(n - 1, 0);

    //Pick and place k gas stations:
    for (int gasStations = 1; gasStations <= k; gasStations++) {
        //Find the maximum section
        //and insert the gas station:
        long double maxSection = -1;
        int maxInd = -1;
        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength =
                diff / (long double)(howMany[i] + 1);
            if (sectionLength > maxSection) {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        //insert the current gas station:
        howMany[maxInd]++;
    }

    //Find the maximum distance i.e. the answer:
    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++) {
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength =
            diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
