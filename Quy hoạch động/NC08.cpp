#include <bits/stdc++.h>

using namespace std;

vector <int> w(100), c(100);

// void xuly(int n, int kltui) {
//     priority_queue<pair<double, int>> maxHeap;
//     for (int i = 0; i < n; ++i) {
//         maxHeap.push({double(c[i]) / double(w[i]), i});
//     }
//     int tongkl = 0, giatri = 0;
//     while (!maxHeap.empty()) {
//         pair<double, int> tmp = maxHeap.top();
//         maxHeap.pop();
//         if (tongkl + w[tmp.second] <= kltui) {
//             tongkl += w[tmp.second];
//             giatri += c[tmp.second];
//         }
//     }
//     cout << tongkl << " " << giatri;
// }

int dp[500];
void xuly(int n, int kltui) {
    for (int i = 1; i <= n; ++i) {
        for (int j = kltui; j >= w[i]; j--) {
            dp[j] = max (dp[j], dp[j - w[i]] + c[i]);
        }
    }
    cout << dp[kltui];
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, kltui;
    cin >> n >> kltui;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) cin >> c[i];
    xuly(n, kltui);
    return 0;
}