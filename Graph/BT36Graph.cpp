#include <bits/stdc++.h>

using namespace std;

int height[100], n;
set <int> ke[100];

void chieuCaoCuaNode () {
    memset(height, -1, sizeof(height));
    queue <int> Queue;
    Queue.push(1);
    height[1] = 0;

    while (!Queue.empty()) {
        int u = Queue.front(); Queue.pop();
        for (int v : ke[u]) {
            if (height[v] == -1) {
                height[v] = height[u] + 1;
                Queue.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) cout << height[i] << " ";
}

void init(int n) {
    int m = n - 1;
    while (m--) {
        int i, j; 
        cin >> i >> j;
        ke[i].insert(j);
        ke[j].insert(i);
    }
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    init(n);
    chieuCaoCuaNode();
    return 0;
}