#include <bits/stdc++.h>

using namespace std;

int xuly (vector <vector <char>> a, int n) {
    vector <vector <int>> dp(n, vector <int> (n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == '*') {
                dp[i][j] = 0;
            }
            else {
                if (i-1 >= 0) {
                    dp[i][j] += dp[i-1][j];
                }
                if (j-1 >= 0) {
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
    }
    return dp[n-1][n-1];
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <vector <char>> a(n,vector<char> (n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    cout << xuly(a, n);
    return 0;
}