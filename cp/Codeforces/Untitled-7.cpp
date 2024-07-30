#include<bits/stdc++.h>

using namespace std;

int main(){
        int t_Shiv;
        cin>>t_Shiv;
        while(t_Shiv--){
            int n;
            int x;
            cin>>n>>x;
            long long count = 0;
        for (int p = 1; p <= x; ++p) {
            int bmaxi = min(x - p, n / p);
            for (int q = 1; q <= bmaxi; ++q) {
                int cmaxo = min(x - p - q, (n - p * q) / (p + q));
                count += max(0, cmaxo);
            }
        }
        cout<<count<<endl;
        }

    

    return 0;
}