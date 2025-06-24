#include <bits/stdc++.h>

using namespace std;

int xuly16(vector <int> A, int n) {
    vector <int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < A.size(); ++j) {
            if (i-A[j] >= 0){
                dp[i] += dp[i-A[j]];
            }
        }
    }
    return dp[n];
}

int xuly17(vector <int> A, int n) {
    vector <int> dp(n + 1, 0);
    dp[0] = 1;
    for (auto coin : A) {
        for (int i = 1; i <= n; ++i) {
            if (i - coin >= 0) {
                dp[i] += dp[i-coin];
            }
        }
    }
    return dp[n];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> k >> n;
    vector <int> a(k);
    for (int i = 0; i < k; ++i) cin >> a[i];
    cout << xuly17(a, n);
    return 0;
}

// 3 8
// 2 3 5

// 0 1 2 3 4 5 6 7 8 9
// 1 0 1 0 1 0 1 0 1 0
// 1 0 1 1 1 1 2 1 2 2
// 1 0 1 1 1 2 2 2 3 3