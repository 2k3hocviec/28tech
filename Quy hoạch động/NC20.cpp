#include <bits/stdc++.h>

using namespace std;

int xuly (vector <vector <int>> matrix, int m, int n) {
    vector <vector <int>> dp(m+1, vector <int> (n+1, 0));
    int res = INT_MIN;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1){
                dp[i+1][j+1] = min({dp[i][j] + 1, dp[i+1][j], dp[i][j+1]}) + 1;
                res = max (res, dp[i+1][j+1]);
            }
            else {
                dp[i+1][j+1] = 0;
            }
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m, n;
    cin >> m >> n;
    vector <vector <int>> a(m, vector <int> (n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    cout << xuly(a, m, n);
    return 0;
}