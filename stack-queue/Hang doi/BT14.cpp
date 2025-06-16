#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <vector>

using namespace std;

bool check(string str) {
    set <char> a;
    for (char c : str){
        if (a.find(c) != a.end()){
            return false;
        }
        a.insert(c);
    }
    return true;
}

int sinh(int a, int b){
    queue <string> Q;
    for (int i = 1; i <= 5; ++i){
        Q.push(to_string(i));
    }
    int res = 0;

    while (!Q.empty()) {
        string s = Q.front(); 
        Q.pop();
        int num = stoi(s);
        if (num >= a && num <= b) res++;
        if (num > b) continue;
        for (int i = 0; i <= 5; ++i) {
            if (check(s + to_string(i))) {
                Q.push(s + to_string(i));
            }
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t; cin >> t ;
    while (t--) {
        int L, R;
        cin >> L >> R;
        cout << sinh(L, R) << endl;
    }
    return 0;
}