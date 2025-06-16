#include <bits/stdc++.h>

using namespace std;

int xuly(string str) {
    int balance = 0, move = 0;
    for (char i : str) {
        if (i == '(') balance++;
        if (i == ')') balance--;
        if (balance < 0) {
            move++;
            balance = 0;
        }
    }
    return move;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    cout << xuly(str);
    return 0;
}