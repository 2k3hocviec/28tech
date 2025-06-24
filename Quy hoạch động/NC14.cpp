#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int quyHoachDong(int N) {
    vector <int> dp(N+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i - j >= 0) {
                dp[i] = (dp[i-j] + dp[i]) % mod;
            }
        }
    }
    return dp[N];
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    cout << quyHoachDong(n);
    return 0;
}