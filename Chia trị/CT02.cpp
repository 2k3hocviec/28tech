#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long daoso(long long N) {
    long long tmp = N, j = 0;
    while (tmp != 0) {
        tmp /= 10;
        j++;
    }
    long long res = 0;
    while (N != 0) {
        res += (N % 10) * pow(10,j - 1);
        j--;
        N /= 10;
    }
    return res;
}

long long luythua (long long N, long long K) {
    if (K == 0) return 1;
    if (K == 1) return N % mod;
    long long half = luythua(N, K/2);
    if (K % 2 == 1) return (((half% mod * half% mod) % mod) * (N % mod)) % mod;
    else return (half% mod * half% mod) % mod;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long i;
    cin >> i;
    cout << luythua(i, daoso(i));
    return 0;
}
