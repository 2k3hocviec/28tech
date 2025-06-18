#include <iostream>
#include <queue>
#include <string>
using namespace std;


void print(int n) {
    queue <string> Q; 
    Q.push("1");
    for (int i = 1; i <= n; ++i) {
        string s = Q.front(); Q.pop();
        cout << s << " ";
        Q.push(s + "0");
        Q.push(s + "1");
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    print(n);
    return 0;
}