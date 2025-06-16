#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

string xuly(string str) {
    stack <string> res;
    for (auto it : str) {
        if (isalpha(it)) {
            res.push(string(1, it));
        }
        else {
            string b = res.top(); res.pop();
            string a = res.top(); res.pop();
            res.push("(" + a + it + b + ")");
        }
    }
    return res.top();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    cout << xuly(str);
    return 0;
}