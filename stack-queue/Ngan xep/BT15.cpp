#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int xuly(string str){
    stack <int> st; 
    for (char it : str){
        if (isdigit(it)) {
            st.push(it - '0');
        } 
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (it == '+'){
                st.push(a + b);
            }
            else if (it == '-') {
                st.push(a - b);
            }
            else if (it == '*') {
                st.push(a * b);
            }
            else if (it == '/') {
                st.push(a / b);
            }
        }
    }
    return st.top();
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    cout << xuly(str);
    return 0;
}