#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

bool kiemtra(string str){
    stack <char> a;
    for (auto i : str){
        if (i == '{' || i == '[' || i == '('){
            a.push(i);
        }
        else{
            if (a.empty()) return false;
            if (i == ')' && a.top() == '(') a.pop(); 
            if (i == ']' && a.top() == '[') a.pop(); 
            if (i == '}' && a.top() == '{') a.pop(); 
        }
    }
    return a.empty();
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t; 
    while (t--){
        string str;
        cin >> str;
        cout << kiemtra(str) << endl;
    }
    return 0;
}