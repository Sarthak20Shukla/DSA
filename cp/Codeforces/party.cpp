#include<bits/stdc++.h>




using namespace std;

using ll = long long;

void samadhan() {
    ll NumBBER;
    cin >> NumBBER;
    vector<ll> shiv(NumBBER);
    for (int i = 0; i < NumBBER; i++) cin >> shiv[i];

    ll largest_odd = 0; 
    ll largest_even = 0; 

    for (int i = 0; i < NumBBER; i++) {
        if (shiv[i] % 2 == 1 && shiv[i] > largest_odd)
            largest_odd = shiv[i];
        if (shiv[i] % 2 == 0 && shiv[i] > largest_even)
            largest_even = shiv[i];
    }

    int c = 0;
    bool paRIty = true;
    for (int i = 1; i < NumBBER; i++) {
        if (shiv[i] % 2 != shiv[0] % 2) {
            paRIty = false;
            break;
        }
    }

    if (paRIty) {
        cout << 0 << endl;
        return;
    }

    sort(shiv.begin(), shiv.end());
    for (int i = 0; i < NumBBER; i++) {
        if (shiv[i] % 2 == 0 && shiv[i] < largest_odd) {
            c++;
            shiv[i] = shiv[i] + largest_odd;
            largest_odd = max(largest_odd, shiv[i]);
        }
    }

    paRIty = true;
    for (int i = 1; i < NumBBER; i++) {
        if (shiv[i] % 2 != shiv[0] % 2) {
            paRIty = false;
            break;
        }
    }

    if (paRIty) {
        cout << c << endl;
        return;
    }

    ll indeX = 0; 
    for (int i = 0; i < NumBBER; i++) {
        if (shiv[i] % 2 != 0 && shiv[i] == largest_odd) {
            indeX = i;
            break;
        }
    }

    shiv[indeX] = largest_odd + largest_even;
    c++;

    for (int i = 0; i < NumBBER; i++) {
        if (shiv[i] % 2 == 0) {
            c++;
        }
    }

    cout << c << endl;
}

int main() {
    ll testVishnu;
    cin >> testVishnu;
    while (testVishnu--) {
        samadhan();
    }
    return 0;
}    