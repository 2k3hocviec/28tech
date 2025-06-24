#include <bits/stdc++.h>

using namespace std;

int xuly(int n) {
    vector <int> dp (n+1);
    for (int i = 1; i <= n; ++i) dp[i] = i;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j*j <= i; ++j){
            dp[i] = min(dp[i - j*j] + 1, dp[i]);
        }
    }
    return dp[n];
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    cout << xuly(n);
    return 0;
}