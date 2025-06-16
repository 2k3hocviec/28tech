#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;

string res(int N){
    queue <string> Q;
    Q.push("8");
    set<int> visited;
    while (!Q.empty()) {
        string s = Q.front();
        Q.pop();
        int du = 0;
        for (char c : s){
            du = (du*10 + (c - '0')) % N;
        }
        if (du == 0) return s;
        //if (!visited.count((du * 10) % N)) {
            Q.push(s + "0");
            //visited.insert((du * 10) % N);
        //}
        //if (!visited.count((du * 10 + 8) % N)) {
            Q.push(s + "8");
            //visited.insert((du * 10 + 8) % N);
        //}
    }
    return "-1";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t; cin >> t;
    while (t--) {
        int N; cin >> N;
        cout << res(N) << endl;
    }
    return 0;
}