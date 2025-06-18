#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9 + 7;

long long luythua(long long i, long long k) {
    if (k == 0) return 1;
    if (k == 1) return i%mod;
    long long half = luythua(i, k/2);
    if (k % 2 == 1) return ((half * half)%mod * i%mod) % mod;
    else return (half * half) % mod;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n, k;
    cin >> n >> k;
    long long A[10][10];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j]; 
            A[i][j] = luythua(A[i][j], k);
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}