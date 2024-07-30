#include<bits/stdc++.h>
using namespace std;

int main(){

    int T_Brahma;
    cin >> T_Brahma;
    while (T_Brahma--) {
        int n_string, q_queue;
        cin >> n_string >> q_queue;
        string aString, bString;
        cin >> aString >> bString;

         vector<vector<int>> pre_freq_A(n_string + 1, vector<int>(26, 0));
        vector<vector<int>> pre_freq_B(n_string + 1, vector<int>(26, 0));

        for (int i = 0; i < n_string; ++i) {
            for (int j = 0; j < 26; ++j) {
                pre_freq_A[i + 1][j] = pre_freq_A[i][j];
                pre_freq_B[i + 1][j] = pre_freq_B[i][j];
            }
            pre_freq_A[i + 1][aString[i] - 'a']++;
            pre_freq_B[i + 1][bString[i] - 'a']++;
        }
        while (q_queue--) {
            int lol, ror;
            cin >> lol >> ror;
            --lol; --ror;   vector<int> freq_A(26, 0), freq_B(26, 0);
            for (int i = 0; i < 26; ++i) {
                 freq_A[i] = pre_freq_A[ror + 1][i] - pre_freq_A[lol][i];
                freq_B[i] = pre_freq_B[ror + 1][i] - pre_freq_B[lol][i];
            }
            int chngs = 0;
            for (int i = 0; i < 26; ++i) {
                chngs += abs(freq_A[i] - freq_B[i]);
            }

            cout << chngs / 2 << endl;
        }
    }
    return 0;
}
