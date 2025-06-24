#include <bits/stdc++.h>

using namespace std;

int dp[100];

int xuly(int n, int k) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (dp[n] != 0) return dp[n];
    for (int i = 1; i <= k; i++) {
        dp[n] += xuly(n - i, k);
    }
    return dp[n];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    memset(dp, 0, sizeof(dp));
    cout << xuly(n, k);
    return 0;
}