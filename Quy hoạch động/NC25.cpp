#include <bits/stdc++.h>

using namespace std;

int xuly(string str1, string str2) {
    int m = str1.size(), n = str2.size();
    vector <vector <int>> dp (m + 1, vector <int> (n + 1));
    for (int i = 1; i <= m; ++i) {
        dp[i][0] = i;
    }
    for (int j = 1; j <= n; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <=m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }
        }
    }

    return dp[m][n];
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string str1, str2;
    cin >> str1 >> str2;
    cout << xuly(str1, str2);
    return 0;
}