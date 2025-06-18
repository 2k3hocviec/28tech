#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

//Một dấu ngoặc được coi là dư thừa nếu giữa hai dấu ngoặc liên tiếp không có toán tử nào (+, -, *, /)

using namespace std;

bool kiemtra(string str){
    stack <char> a;
    int dau = 0;
    for (char c : str) {
        if (c == ')'){
            bool codau = false;
            while (a.top() != '(') {
                if (a.top() == '+' || a.top() == '-' || a.top() == '*' || a.top() == '/') {
                    codau = true;
                }
                a.pop();
            } 
            if (codau == false) return false;
        }
        else {
            a.push(c);
        }
    }
    return true;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    cout << kiemtra(str);
    return 0;
}