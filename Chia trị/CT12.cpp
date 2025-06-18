#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long memo[1000];

long long fibo (int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (memo[n] != 0 ) return memo[n];
	memo[n] = (fibo(n-2) + fibo(n-1)) % mod;
	return memo[n];
}

long long fibo1(long long n) {
    if (n == 0) return 0;
    long long a = 0, b = 1;
    for (long long i = 2; i <= n; ++i) {
        long long c = (a + b) % mod;
        a = b;
        b = c;
    }
    return b;
}

int main() {
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; 
    cin >> n;
    cout << fibo1(n);
	return 0;
}
