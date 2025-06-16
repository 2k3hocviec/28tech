#include <bits/stdc++.h>

using namespace std;

int xuly(vector <int> A) {
    sort(A.begin(), A.end());
    int wait = 0, res = 0;
    for (auto i : A) {
        if (wait <= i) {
            res++;
            wait += i;
        }
    }
    return res;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <int> a(n);
    while (n--) {
        cin >> a[n];
    }
    cout << xuly(a);
    return 0;
} 