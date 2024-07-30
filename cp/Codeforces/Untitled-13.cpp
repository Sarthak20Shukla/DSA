#include<bits/stdc++.h>

using namespace std;

int mulyankan(int lamba, string strg) {
    int mulya = 0;
    stack<int> sttk;
    for (int i = 0; i < lamba; i += 2) {
        if (strg[i] == '_') {
            if (i == 0 || strg[i - 1] == ')') {
                strg[i] = '(';
            } else {
                strg[i] = ')';
            }
        }
    }

    for (int i = 0; i < lamba; ++i) {
        if (strg[i] == '(') {
            sttk.push(i);
        } else if (strg[i] == ')') {
            if (!sttk.empty()) {
                mulya += i - sttk.top();
                sttk.pop();
            }
        }
    }

    return mulya;
}


int main(){
    int TeStCasEs;

    cin >> TeStCasEs;

    while(TeStCasEs--) {
        int lamba;
        cin >> lamba;

        string strg;
        cin >> strg;

        int ansVishnu = mulyankan(lamba, strg);
        cout << ansVishnu << endl;
    }

    return 0;
}

