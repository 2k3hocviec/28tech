#include <bits/stdc++.h>

using namespace std;

string memo[100];

string xuLy(long long N) {
    if (N == 1) return "A";
    if (N == 2) return "B";
    if (memo[N] != "") return memo[N];
    memo[N] = xuLy(N-2) + xuLy(N-1);
    return memo[N]; 
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n;
    cin >> n;
    string s = xuLy(n);
    cout << s << endl;
    long long k;
    cin >> k;
    cout << s[k-1] << endl;
    return 0;
}