#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

int xuly (vector <vector <int >> a) {
    int n = a.size();
    vector <int> dp (n, 0);
    dp[0] = a[0][2];
    for (int i = 1; i < n; ++i) {
        dp [i]= dp[i-1];
        for (int j = i-1; j >= 0; --j) {
            if (a[j][1] <= a[i][0]){
                dp[i] = max(dp[i], dp[j] + a[i][2]);
                break;
            }
        }
        dp[i] = max(dp[i], a[i][2]);
    }
    return dp[n-1];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <vector <int>> a;
    for (int i = 0; i < n; ++i) {
        int ai, bi, pi;
        cin >> ai >> bi >> pi;
        a.push_back({ai, bi, pi});
    }
    sort(a.begin(), a.end(), cmp);
    cout << xuly(a);
    return 0;
}