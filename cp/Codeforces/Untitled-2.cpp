#include <bits/stdc++.h>
using namespace std;
#define int long long

int findMinRemovals(int k, vector<int>& el) {
    int curX = 0, cnt = 0;
    for (auto& i : el) {
        if (i > k) continue;
        curX |= i;
        cnt++;
    }
    
    return (curX == k ? el.size() - cnt : el.size());
}

signed main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> el(n);
        for (auto& i : el) cin >> i;
        
        int minRe = n;
        for (int i = 0; i < 32; i++) {
            int k = (1 << i) - 1;
            minRe = min(minRe, findMinRemovals(k, el));
        }
        
        cout << minRe << endl;
    }
    
    return 0;
}