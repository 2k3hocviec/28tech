#include <bits/stdc++.h>

using namespace std;

map <long long, long long> memo;

long long xuly(int n) {
    if (n == 0) return 1;
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    long long total = 0;
    for (int i = 1; i <= n; ++i) {
        total += xuly(n - i);
    }
    memo[n] = total;
    return total;
}

int main () {
    int n;
    cin >> n;
    cout << xuly(6);
    return 0;
}