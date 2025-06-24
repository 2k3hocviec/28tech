#include <bits/stdc++.h>

using namespace std;

int dp[1001];

int mangConTangDaiNhat(vector <int> A) {
    fill (dp, dp + A.size(), 1);
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp, dp + A.size());
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    cout << A.size() - mangConTangDaiNhat(A);
    return 0;
}