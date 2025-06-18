#include <bits/stdc++.h>

using namespace std;

int sumMax2phia(vector <int> a, int l, int m, int r) {
    int sum = 0, left_sum = INT_MIN, right_sum = INT_MIN;
    for (int i = m; i >= l; --i) {
        sum += a[i];
        left_sum = max(left_sum, sum);
    }
    sum = 0; 
    for (int i = m + 1; i <= r; ++i) {
        sum += a[i];
        right_sum = max(right_sum, sum);
    }
    return left_sum + right_sum;
}

int xuly (vector <int> a, int l, int r) {
    if (l == r) return a[l];
    int m = (l + r) / 2;
    int left = xuly (a, l, m);
    int right = xuly(a, m + 1, r);
    int cross = sumMax2phia(a, l, m, r);
    return max({left, right, cross});
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; 
    cin >> n;
    vector <int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    cout << xuly(A, 0, n - 1);
    return 0;
}