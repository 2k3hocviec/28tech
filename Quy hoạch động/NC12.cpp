#include <bits/stdc++.h>

using namespace std; 

int xuly (vector <int> A) {
    int n = A.size();
    vector <int> dp(n);
    for (int i = 0; i < n; ++i) {
        dp[i] = A[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j]) {
                dp[i] = max (dp[i], dp[j] + A[i]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    cout << xuly(A);
    return 0;
}