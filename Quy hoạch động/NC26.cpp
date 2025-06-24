#include <bits/stdc++.h>

using namespace std;

int xuly (vector <int> A, int n) {
    vector <int> dp (n-1, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j){
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
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
    cout << xuly(A, n);
}