#include <bits/stdc++.h>

using namespace std;

int xuly(string a, string b){
    int n = a.size(), m = b.size();
    int A[n+1][m+1];
    memset(A, 0, sizeof(A));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i-1] == b[j-1])  {
                A[i][j] = A[i-1][j-1] + 1;
            }
            else {
                A[i][j] = max(A[i-1][j], A[i][j-1]);
            }
        }
    } 
    return A[n][m];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string a,b;
    cin >> a >> b;
    cout << xuly(a, b);
    return 0;
}