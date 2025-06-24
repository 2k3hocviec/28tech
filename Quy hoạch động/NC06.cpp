#include <bits/stdc++.h>

using namespace std;

int dp[100];

int xuly (int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (dp[n] != 0) return dp[n];
    dp[n] = xuly(n-1) + xuly(n-2) + xuly(n-3);
    return dp[n];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    cout << xuly(n);
    return 0;
}