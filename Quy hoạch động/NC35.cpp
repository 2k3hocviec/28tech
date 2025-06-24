#include <bits/stdc++.h>

using namespace std;

int xuly(vector <int> A, int n) {
    vector <int> prefix(n, 0);
    for (int i = 0; i < n; ++i) {
        if (A[i] % 2 == 0) prefix[i] = -1;
        else prefix[i] = 1;
    }
    int prefix_sum = 0, ans = 0;
    map <int, int> count; 
    count[0] = 1;
    for (int i = 0; i < n ; ++i) {
        prefix_sum += prefix[i];
        if (count.find(prefix_sum) != count.end()) {
            ans += count[prefix_sum];
            count[prefix_sum]++;
        }
        else {
            count[prefix_sum] = 1;
        }
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; 
    cin >> n;
    vector <int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    cout << xuly(A, n);
    return 0;
}