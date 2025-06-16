#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int eval(const string& s, int& i) {
    int res = 0;
    char op = '+';
    while (i < s.size()) {
        if (s[i] == '(') {
            ++i;
            int val = eval(s, i);
            if (op == '+') res += val;
            else if (op == '-') res -= val;
            else if (op == '*') res *= val;
            else if (op == '/') res /= val;
        } else if (isdigit(s[i])) {
            int val = s[i] - '0';
            if (op == '+') res += val;
            else if (op == '-') res -= val;
            else if (op == '*') res *= val;
            else if (op == '/') res /= val;
        } else if (s[i] == ')') {
            ++i;
            return res;
        } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            op = s[i];
        }
        ++i;
    }
    return res;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    stack <string> st;
    for (int i = str.size() - 1; i >= 0; --i){
        if (isdigit(str[i])) {
            st.push(string(1, str[i]));
        }
        else {
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            st.push("(" + a + str[i] + b + ")");
        }
    }
    cout << st.top() << endl;
    int i = 0;
    cout << eval(st.top(), i);
    return 0;
}