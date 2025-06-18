#include <bits/stdc++.h>

using namespace std;

int floor (vector <int> A, int X, int l, int r, int res = -1) {
    if (l > r) return res;
    int m = (l + r) / 2;
    if (A[m] > X) return floor (A, X, l, m - 1, res);
    else return floor(A, X, m + 1, r , A[m]);
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, X;
    cin >> n >> X;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << floor(a, X, 0, n-1, -1);
    return 0;
}