#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int kiemtra(string str){
    stack <char> a;
    for (char c : str){
        if (a.empty()) a.push(c);
        if (a.top() == '(' && c == ')'){
            a.pop();
        }
        else a.push(c);
    }
    return a.size() / 2;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    cout << kiemtra(str);
    return 0;
}