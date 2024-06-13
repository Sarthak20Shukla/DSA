//evaluate BOOLEAN Exp
int M = 1e9 + 7;
long long f(int i, int j, int isTrue, string& s,
            vector<vector<vector<int>>>& dp) {
    if (i > j)
        return 0;
    if (i == j) {
        if (isTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    long long ans = 0;
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        long long lT = f(i, ind - 1, 1, s, dp);
        long long lF = f(i, ind - 1, 0, s, dp);
        long long rT = f(ind + 1, j, 1, s, dp);
        long long rF = f(ind + 1, j, 0, s, dp);
        if (s[ind] == '&') {
            if (isTrue)
                ans = (ans + (lT * rT) % M) % M;
            else
                ans = (ans + (rT * lF) % M + (rF * lT) % M + (rF * lF) % M) % M;
        } else if (s[ind] == '|') {
            if (isTrue) {
                ans = (ans + (lT * rT) % M + (lT * rF) % M + (lF * rT) % M) % M;
            } else
                ans = (ans + (rF * lF) % M) % M;
        } else {
            if (isTrue) {
                ans = (ans + (lT * rF) % M + (lF * rT) % M) % M;
            } else {
                ans = (ans + (lT * rT) % M + (lF * rF) % M) % M;
            }
        }
    }
    return dp[i][j][isTrue] = ans % M;
}
int evaluateExp(string& s) {
    int n = s.size();
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
    return f(0, s.size() - 1, 1, s, dp);
}