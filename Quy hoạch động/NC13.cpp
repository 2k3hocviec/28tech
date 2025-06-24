#include <bits/stdc++.h>

using namespace std;

int xuly(vector <int> A) {
    int n = A.size();
    vector <int> inc(n), dec(n);
    for (int i = 0; i < n; ++i) {
        inc[i] = A[i];
        dec[i] = A[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[j] < A[i]) {
                inc[i] = max (inc[i], inc[j] + A[i]);
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[j] > A[i]) {
                dec[i] = max (dec[i], dec[j] + A[i]);
            }
        }
    }

    int max_sum = INT_MIN;
    for (int i = 0; i < n; ++i) {
        max_sum = max(max_sum, inc[i] + dec[i] - A[i]);
    }
    return max_sum;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    cout << xuly(A);
    return 0;
}