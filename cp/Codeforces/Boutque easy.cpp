//Boutque easy
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int p = 1e9 + 7;

long long pow(long long x, long long q) {
    if (q == 0) {
        return 1;
    }
    long long i = pow(x, q / 2);
    if (q % 2 == 0) {
        return (i * i) % p;
    }
    return (i * i * x) % p;
}

void solve() {
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    unordered_map<long long, long long> hs;
    for (long long x : a) {
        hs[x]++;
    }
    
    long long ans = 0;
    for (const auto& pair : hs) {
        long long x = pair.first;
        long long y = pair.second;
        long long l = min(m / x, y);
        ans = max(ans, l * x);
        
        if (hs.find(x + 1) == hs.end()) {
            continue;
        }
        
        long long z = hs[x + 1];
        for (long long i = 1; i <= y; i++) {
            if (i * x > m) {
                break;
            }
            long long du = m - i * x;
            long long su = min(du / (x + 1), z) * (x + 1) + i * x;
            ans = max(su, ans);
        }
    }
    cout << ans << endl;
}

int main() {
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++) {
        solve();
    }
    return 0;
}

