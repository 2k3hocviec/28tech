#include <bits/stdc++.h>

using namespace std;


int xuly (int a, int b) {
    vector <vector <int>> dp (a+1, vector <int> (b+1, 10000000));
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == j) dp[i][j] = 0;
            else {
                for (int k = 1; k < i; ++k) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
                }
                for (int k = 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
                } 
            }
        }
    }
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            cout << dp[i][j] << " "; 
        }
        cout << endl;
    }
    return dp[a][b];
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << xuly (a, b);
    return 0;
}