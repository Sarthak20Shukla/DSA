#include<bits/stdc++.h>

using namespace std;

int restoreAndCalculateCost(int length, string sequence) {
    for (int index = 0; index < length; index += 2) {
        if (sequence[index] == '_') {
            if (index == 0 || sequence[index - 1] == ')') {
                sequence[index] = '(';
            } else {
                sequence[index] = ')';
            }
        }
    }

    int cost = 0;
    stack<int> stack;

    for (int index = 0; index < length; ++index) {
        if (sequence[index] == '(') {
            stack.push(index);
        } else if (sequence[index] == ')') {
            if (!stack.empty()) {
                cost += index - stack.top();
                stack.pop();
            }
        }
    }

    return cost;
}

int main(){
    int TeStCasEs;
    cin >> TeStCasEs;

    while(TeStCasEs--) {
        int lamba;
        cin >> lamba;

        string strg;
        cin >> strg;

        int result = restoreAndCalculateCost(lamba, sequence);
        cout << result << endl;
    }

    return 0;
}
