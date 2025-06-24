#include <bits/stdc++.h>

using namespace std;

// int xuly(vector <int> A) {
//     int n = A.size();
//     vector <int> dp(n);
//     dp = A;
//     for (int i= 0; i < n; ++i) {
//         for (int j = i + 2; j < n; ++j) {
//             dp[j] = max(dp[i] + A[j], dp[j]); 
//         }
//     }
//     return *max_element(dp.begin(), dp.end());
// }

int xuly (vector <int> A) {
    int n = A.size();
    if (n == 0) return 0;
    if (n == 1) return A[1];
    vector <int> dp(n);
    dp[0] = A[0];
    dp[1] = max(A[0], A[1]);
    for (int i = 2; i < n; ++i) {
        dp[i] = max(dp[i-1], dp[i-2] + A[i]);
    }
    return dp[n-1];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    cout << xuly(a);
    return 0;
}