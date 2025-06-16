#include <bits/stdc++.h>

using namespace std;

int xuly (string str) {
    int res = 0;
    int n = str.size();
    vector <int> a (n ,0);
    str[0] == '1' ? a[0] = 1 : a[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (str[i] == '1') {
            a[i] = a[i-1] + 1;
            a[i - 1] = 0;
        }
        else {
            a[i] = 0;
        }
    }
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i += 2) {
        res += a[i];
    }
    return res;
}

int main () {
    string str= "1000101110011111";
    cout << xuly(str);
    return 0;
}