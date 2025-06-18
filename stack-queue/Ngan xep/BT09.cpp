#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    stack <string> st;
    for (int i = str.size() - 1; i >= 0; --i){
        if (isalpha(str[i])) {
            st.push(string(1, str[i]));
        }
        else {
            string a = st.top(); st.pop();
            string b = st.top(); st.pop();
            st.push("(" + a + str[i] + b + ")");
        }
    }
    cout << st.top();
    return 0;
}