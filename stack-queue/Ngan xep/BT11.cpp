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
    stack <char> st;
    string res;
    for (auto i : str) {
        if (isalpha(i)) {
            res += i;
        }    
        else if (i == ')'){
            while (st.top() != '(') {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            st.push(i);
        } 
    }
    cout << res;
    return 0;
}