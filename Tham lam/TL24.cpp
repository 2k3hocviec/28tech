#include <bits/stdc++.h>

using namespace std;

bool palindrome (string str) {
    map <char , int> cnt;
    int odd = 0;

    for (int i = 0; i < str.size(); ++i) {
        cnt[str[i]]++;
    }

    for (auto it : cnt) {
        if (it.second % 2) odd++;
    }

    return odd <= 1;
}

string game(string str) {
    if (palindrome(str)) return "Ti";
    if (str.size() % 2) return "Ti";
    else return "Teo"; 
}

int main () {
    string str;
    cin >> str;
    cout << game(str);
    return 0;
}