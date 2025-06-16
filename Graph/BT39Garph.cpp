#include <bits/stdc++.h>

using namespace std;

int n, m, s, chuaxet[100];
set <int> Ke[100];
vector <pair<int, int >> res;

void Init(){
    cin >> n >> m >> s;
    while (m--){
        int i, j;
        cin >> i >> j;
        Ke[i].insert(j);
        Ke[j].insert(i);
    }
}

void ktao(){
    for (int i = 1; i <= n; ++i) chuaxet[i] = true;
}

void Tree_DFS(int u){
    chuaxet[u] = false;
    for (auto v : Ke[u]){
        if (chuaxet[v] == true){
            chuaxet[v] = false;
            res.push_back({u, v});            
            Tree_DFS(v);
        }
    }
}

void In(){
    for (auto it : res){
        cout << it.first << "->" << it.second << endl;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    ktao();
    Tree_DFS(s);
    In();
    return 0;
}