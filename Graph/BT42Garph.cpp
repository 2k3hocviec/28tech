#include <bits/stdc++.h>

using namespace std;

int n, parent[101], m, sz[101], tmp;

void ktao(){
    for (int i = 1; i <= 100; ++i){
        parent[i] = i;
        sz[i] = 1;
    }
}

int Find(int u){
    if (parent[u] = u) return u;
    else return parent[u] = Find(parent[u]);
}

bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if (u == v) return false;
    if (sz[u] < sz[v]){
        swap(u, v);
    }
    sz[u] += sz[v];
    parent[v] = u;
    tmp = max(tmp, sz[u]);
    return true;
}

void Init(){
    cin >> n >> m;
    while(m--){
        int i, j;
        cin >> i >> j;
        if (Union(i, j)){
            n--;
            cout << n << " " << tmp << endl;
        }     
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ktao();
    Init();
    return 0;
}