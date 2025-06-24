#include <bits/stdc++.h>

using namespace std;

void xuly(string str) {
    int n = str.length(), res = 0, start = 0;
    vector <vector<bool>> dp(n, vector <bool> (n, false));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
        res = 1;
    }
    for (int i = 1; i < n; ++i) {
        if (str[i] == str[i-1]) {
            dp[i-1][i] = true;
            res = 2;
            start = i - 1;
        }
    }
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (str[i] == str[j] && dp[i+1][j-1] == true) {
                dp[i][j] = true;
                if (len > res) {
                    start = i;
                    res = len;
                }
            }
        }
    }
    cout << str.substr(start, res) << endl << res;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    xuly(str);
    return 0;
}