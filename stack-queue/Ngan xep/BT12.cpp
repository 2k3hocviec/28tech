#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

string xuly(string str){
    stack <string> st;
    for (auto i : str) {
        if (isalpha(i)){
            st.push(string(1, i));
        }
        else{
            string b = st.top(); st.pop();
            string a = st.top(); st.pop();
            st.push(i + a + b);
        }
    }
    return st.top();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    cout << xuly(str);
    return 0;
}