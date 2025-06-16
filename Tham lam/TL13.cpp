#include <bits/stdc++.h>

using namespace std;

bool check(string str) {
    map <char, int> cnt;
    int n = 0;
    for (char c : str) {
        cnt[c]++;
        if (cnt[c] > n) {
            n = cnt[c];
        } 
    }
    return n <= (str.size() + 1) / 2;
}

int main() {
    string str;
    cin >> str;
    cout << check(str); 
    return 0;
}