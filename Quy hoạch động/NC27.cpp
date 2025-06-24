#include <bits/stdc++.h>

using namespace std;

string subtractStrings(string a, string b) {
    int n = a.size(), m = b.size();
    string res = "";
    int carry = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
        int digitA = a[i] - '0';
        int digitB = (i < m ? b[i] - '0' : 0);
        int sub = digitA - digitB - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        res.push_back(sub + '0');
    }
   
    while (res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

int xuly(string n) {
    int dem = 0;
    string number = n;
    while (number != "0") {
        char i = '0';
        for (char c : number) {
            if (i < c) {
                i = c;
            }
        }
        number = subtractStrings(number, string(1, i));
        dem++;
    }
    return dem;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string num;
    cin >> num;
    cout << xuly(num);
    return 0;
}

// nên dùng tham lam