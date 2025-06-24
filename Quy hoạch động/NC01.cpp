#include <iostream>
#include <string>
using namespace std;

int dp [1001][1001];

int mangConChungDaiNhat(string S, string T) {
    int m = S.size(), n = T.size();
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (S[i - 1] == T[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } 
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string S, T;
    cin >> S >> T;
    cout << mangConChungDaiNhat(S, T) << endl;
    for (int i = 1; i <= S.size(); ++i) {
        for (int j = 1; j <= T.size(); ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}