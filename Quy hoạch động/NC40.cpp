#include <bits/stdc++.h>

using namespace std;

void xuly(vector <vector <int>> A) {
    int n = A.size(), m = A[0].size();
    vector <vector<int>> dp(n, vector <int> (m, -100));
    for (int i = 0; i < n; ++i) dp[i][0] = A[i][0];
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i){
            // Từ trên xuống
            if (i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + A[i][j]);
            // Từ ngang
            dp[i][j] = max(dp[i][j], dp[i][j-1] + A[i][j]);
            // Từ dưới lên
            if (i < n-1) dp[i][j] = max(dp[i][j], dp[i+1][j-1] + A[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) cout << dp[i][n-1] << " ";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M;
    cin >> N >> M;
    vector <vector <int>> A(N, vector <int> (M, 0)); 
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }
    xuly(A);
    return 0;
}