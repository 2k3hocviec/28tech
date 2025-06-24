#include <bits/stdc++.h>

using namespace std;

bool xuly (vector <int> &A, int S) {
    vector <bool> dp(S + 1, false);
    dp[0] = true;
    for (int x : A) {
        for (int s = S; s >= x; --s) {
            if (dp[s - x]) {
                dp[s] = true;
            }
        }
    }
    return dp[S];
}

int main () {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, S;
    cin >> n >> S;
    vector <int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    cout << xuly(A, S);
}