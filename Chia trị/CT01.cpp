#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

long long xuly(long long N, long long K) {
    if (K == 0) return 1;
    if (K == 1) return N % mod;
    long long half = xuly(N, K/2);
    if (K % 2 == 1) {
        return (((half * half) % mod) * (N % mod)) % mod;
    }
    else {
        return ((half % mod) * (half % mod)) % mod;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long N, K;
    cin >> N >> K;
    cout << xuly(N, K) << endl;
    return 0;
}