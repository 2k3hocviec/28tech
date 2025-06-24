#include <bits/stdc++.h>

using namespace std;

int xuly (string num) {
    long long res = 0, n = num.size();
    vector <long long> dp(n,0);
    for(int i = 1; i <= n ;++i) {
        dp[i] = dp[i-1]*10 + i * (num[i-1] - '0');
        res += dp[i];
    }
    return res;
}

int main ()  {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string num;
    cin >> num;
    cout <<xuly(num);
    return 0;
}