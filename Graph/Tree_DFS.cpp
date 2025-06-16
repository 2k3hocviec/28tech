#include <bits/stdc++.h>

using namespace std;

int n, m, chuaxet[100];
set <int> Ke[100];
vector <pair <int, int>> res;

void Init(){
    cin >> n >> m;
    while (m--){
        int i, j;
        cin >> i >> j;
        Ke[i].insert(j);
        Ke[j].insert(i);
    }
}

void Reset(){
    for (int i = 1; i <= n; ++i) chuaxet[i] = true;
}

void DFS(int i){
    chuaxet[i] = false;
    for (auto j : Ke[i]){
        if (chuaxet[j] == true){
            DFS(j);
        }
    }
}

void Tree_DFS(int u){
    chuaxet[u] = false;
    for (auto v : Ke[u]){
        if (chuaxet[v] == true){
            res.push_back({u, v});
            Tree_DFS(v);
        }
    }
}

void Tree_BFS(int u){
    queue <int> qe;
    qe.push(u);
    chuaxet[u] = false;
    while (!qe.empty()){
        int i = qe.front();
        qe.pop();
        for (auto j : Ke[i]){
            if (chuaxet[j] == true){
                chuaxet[j] = false;
                qe.push(j);
                res.push_back({i, j});
            }
        }
    }
}

void In(){
    for (auto it : res){
        cout << "(" <<it.first << "," << it.second << ") ";
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    Reset();
    Tree_BFS(1);
    In();
    return 0;
}