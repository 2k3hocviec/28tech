#include <bits/stdc++.h>

using namespace std;

string str (int N) {
    if (N == 1) return "1";
    string s = str(N-1);
    return s + to_string(N) + s;
}

char res (string str, int k) {
    return str[k-1];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    string t = str(n);
    cout << res(t, k);
    return 0;
}