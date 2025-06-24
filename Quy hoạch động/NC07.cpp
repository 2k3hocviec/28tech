#include <bits/stdc++.h>

using namespace std;

int dp[25000];

int xuly(vector <int> w, int n, int k) {
    for (int i = 1; i <= n; ++i) {  
        for (int j = k; j >= w[i]; --j) {
            dp[j] = max(dp[j], dp[j-w[i]] + w[i]);
        }
    }
    return dp[k];
}


int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int k, n;
    cin >> k >> n;
    vector <int> A(n + 1);
    for (int i = 1; i <= n; ++i) cin >> A[i];
    cout << xuly(A, n, k);
    return 0;
}