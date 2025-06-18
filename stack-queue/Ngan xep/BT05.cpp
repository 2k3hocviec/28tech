#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void kiemtra(string str){
    stack <char> a;
    for (auto i : str){
        if (a.empty()) a.push(i);
        else {
            if (a.top() == i) a.pop();
            else{
                a.push(i);
            }
        }
    }
    if (a.empty()) cout << "Rong" << endl;
    else {
        stack <char> tmp = a;
        vector <char> S;
        while (!tmp.empty()){
            S.push_back(tmp.top());
            tmp.pop();
        }
        for (auto it = S.rbegin(); it != S.rend(); ++it) cout << *it ;
        cout << endl;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t; 
    while (t--){
        string str;
        cin >> str;
        kiemtra(str);
    }
    return 0;
}