#include <bits/stdc++.h>

using namespace std;

int n, parent[1000], sz[1000];

void ktao(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        parent[i] = i;
        sz[i] = i;
    }
}

int Find(int u){
    if(u == parent[u])
        return u;
    else
        return parent[u] = Find(parent[u]);
    }

bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if (u == v) return false;
    else if (u < v) parent[v] = u;
    else parent[u] = v;
    return true;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ktao();
    int m;
    cin >> m;
    while (m--){
        int i, j;
        cin >> i >> j;
        Union(i , j);
    }
    for (int i = 1; i <= n; ++i){
        cout << i << " " << parent[i] << endl;
    }
    return 0;
}