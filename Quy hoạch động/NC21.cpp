#include <bits/stdc++.h>

using namespace std;

void xuly (vector <int> A){
    int tong = accumulate(A.begin(), A.end(), 0);
    vector <bool> dp(tong+1, false);
    dp[0] = true;
    for (auto i : A) {
        for (int j = tong; j >= i; --j) {
            if (dp[j - i] == true) {
                dp[j] = true;
            }
        }
    }

    for (int i = 0; i <= tong; ++i) {
        if (dp[i]) cout << i << " ";
    }
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; 
    cin >> n;
    vector <int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    xuly(A);
    return 0;
}
