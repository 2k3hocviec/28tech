#include <bits/stdc++.h>

using namespace std;

map <int, int> xuly(map <int, int> &c, int n) {
    while (n > 0 && !c.empty()) {
        auto it = max_element(c.begin(), c.end(),
            [](const pair<int,int>& a, const pair<int,int>& b) {
                return a.second < b.second;
            });
        if (it->second > n) {
            it->second -= n;
            n = 0;
            break;
        }
        else {
            n -= it->second;
            it->second = 0;
        }
    }
    return c;
}

long long res(string t, int n) {
    long long kq = 0;
    map <int, int> a;
    for (auto it : t) {
        a[toupper(it)]++;
    }
    map <int, int> b = xuly(a, n);
    for (auto it : a) {
        kq += pow(it.second,2);
    }
    return kq;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string t; cin >> t ;
    cout << res(t, 1);
    return 0;
}