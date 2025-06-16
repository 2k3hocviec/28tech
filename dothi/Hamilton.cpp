#include <iostream>
#include <set>
#include <bits/stdc++.h>
using namespace std;

set <int> ke[10];
int n, m;
bool chuaxet[10];
int path[10];

void init(){
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        ke[u].insert(v);
        ke[v].insert(u);
    }
}

void init_matran(){
    int n;
    int a[n+1][n+1];
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
            if (a[i][j]) ke[i].insert(j);
        }
    }

}

void reInit(){
    memset(chuaxet, true, sizeof(chuaxet));
}

int x[10];

void ghinhan(){
    for (int i = 1; i <= n + 1; ++ i){
        cout << x[i] << " ";
    }
}

void hamilton(int k, int start){
    for (auto y : ke[x[k-1]]){
        if (k == n + 1 && y == start){
            x[k] = y;
            ghinhan();
            cout << endl;
        }
        else if (chuaxet[y]){
            x[k] = y;
            chuaxet[y] = false;
            hamilton(k+1, start);
            chuaxet[y] = true;
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);      
    freopen("output.txt", "w", stdout);
    init_matran();
    reInit();
    x[1] = 10;
    chuaxet[10] = false;
    hamilton(2,10);
    // x[1] = v0;
    // chuaxet[v0] = false;
    // hamiltonCycle(2);
    return 0;
}

// 10
// 0 1 0 0 0 1 0 1 0 1
// 1 0 1 0 0 1 0 0 0 1
// 0 1 0 1 0 1 0 0 0 0
// 0 0 1 0 1 0 1 0 0 0
// 0 0 0 1 0 0 1 0 0 0
// 1 1 1 0 0 0 0 0 0 0
// 0 0 0 1 1 0 0 1 1 0
// 1 0 0 0 0 0 1 0 1 0
// 0 0 0 0 0 0 1 1 0 1
// 1 1 0 0 0 0 0 0 1 0