#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

long long func(int X) {
    int p1 = X;
    while (!isPrime(p1)) {
        p1++;
    }
    int p2 = p1 + 1;
    while (!isPrime(p2)) {
        p2++;//hari bola
    }
    return static_cast<long long>(p1) * p2;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int x;
        cin >> x;
        cout << func(X) << endl;//last answer
    }
    
    return 0;
}
