#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;

bool kiemtra(string s, string so){
    if (s.length() < so.length()) return true;
    else if (s.length() > so.length()) return false;
    else return s < so;
}

int soluong(string so){
    queue <string> Q;
    int dem = 0;
    Q.push("1");

    while (!Q.empty()) {
        string s = Q.front();
        Q.pop();
        if (kiemtra(s, so)) {
            dem++;
        }
        else{
            return dem;
        }
        Q.push(s+"0");
        Q.push(s+"1");
    }
    return dem;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t; cin >> t;
    while (t--) {
        string N; cin >> N;
        cout << soluong(N) << endl;
    }
    return 0;
}