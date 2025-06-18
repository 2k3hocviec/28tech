#include <bits/stdc++.h>

using namespace std;

int searchViTri(vector <int> a, vector <int> b) {
    int l = 0, r = a.size() - 2, res = a.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == b[mid]) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
            res= mid;
        }
    }
    return res + 1;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <int> a(n), b(n-1);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n-1; ++i) cin >> b[i];
    cout << searchViTri(a, b);
    return 0;
}