#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <vector>
using namespace std;

vector <string> xuly(int n) {
    vector <string> res;
    queue <string> Q;
    Q.push("6");
    Q.push("8");
    while (!Q.empty()) {
        string s = Q.front();
        Q.pop();
        res.push_back(s);
        string s1 = s + "6", s2 = s + "8";
        if (s1.size() <= n) {
            Q.push(s1);
            Q.push(s2);
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <string> tmp = xuly(n);
    for (auto it = tmp.rbegin(); it != tmp.rend(); ++it){
        cout << *it << " ";
    }
    return 0;
}