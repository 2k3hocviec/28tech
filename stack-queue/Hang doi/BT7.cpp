#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;

bool chiahet(string bichia, int sochia) {
    int du = 0;
    for (char c : bichia) {
        du = (du * 10 + (c - '0')) % sochia;
    }
    return du == 0;
}

string xuly(int n) {
    queue <string> Q;
    Q.push("1");
    while (!Q.empty()) {
        string s = Q.front();
        Q.pop();
        if ((chiahet(s, n))) {
            return s;
        }
        Q.push(s + "0");
        Q.push(s + "1");
    }
    return "-1";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    while (n--) {
        int i;
        cin >> i;
        cout << xuly(i) << endl;
    }
    return 0;
}