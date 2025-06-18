#include <bits/stdc++.h>
#include <chrono>
#include <sstream>

using namespace std;

string xuly(long long n) {
    if (n < 0) return "Invalid input";
    if (n == 0) return "0";
    if (n == 1) return "1";
    string sub = xuly(n / 2);
    stringstream ss;
    ss << sub << (n % 2 == 0 ? "0" : "1") << sub;
    return ss.str();
}

int count(string s ,long long l, long long r) {
    int d = 0;
    for (long long i = l; i <= r; ++i) {
        if (s[i] == '1') d++; 
    }
    return d;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n, l, r;
    cin >> n >> l >> r;

    auto start = chrono::high_resolution_clock::now();

    string s = xuly(n);
    cout << s << endl;
    cout << count(s, l, r) << endl;

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;
    cout << "Time: " << elapsed.count() << " ms" << endl;

    return 0;
}