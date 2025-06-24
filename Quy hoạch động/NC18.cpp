#include <bits/stdc++.h>

using namespace std;

int xuly(vector <vector <int>> A) {
    int n = A.size(), m = A[0].size();
    vector <vector<int>> dp(n, vector <int> (m, 0));
    dp[0][0] = A[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j){
            if (i-1 >= 0) {
                dp[i][j] = max(dp[i-1][j] + A[i][j], dp[i][j]);
            }
            if (j-1 >= 0) {
                dp[i][j] = max(dp[i][j-1] + A[i][j], dp[i][j]);
            }
            if (i-1 >= 0 && j-1 >= 0) {
                dp[i][j] = max(dp[i-1][j-1] + A[i][j], dp[i][j]);
            }
        }
    }
    return dp[n-1][m-1];
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
    cout << xuly(A);
    return 0;
}