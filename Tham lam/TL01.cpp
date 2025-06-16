#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> money = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};

priority_queue <int> xuly() {
    priority_queue <int> Q;
    for (auto i : money) {
        Q.push(i);
    }
    return Q;
}

int tien(priority_queue <int> Q,  int n) {
    int dem = 0, tien = n;
    while (tien > 0 && !Q.empty()) {
        int menhgia = Q.top();
        Q.pop();
        dem += tien/menhgia;
        tien = tien - (tien/menhgia)*menhgia;
    }
    return dem;
}

int main() {
    int n; cin >> n;    
    priority_queue <int> Q = xuly();
    cout << tien(Q, n);
    return 0;
}