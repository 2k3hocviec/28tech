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

void Tree_BFS(int i){
    queue <int> qe;
    qe.push(i);
    chuaxet[i] = false;
    while (!qe.empty()){
        int u = qe.front();
        qe.pop();
        for (auto v : Ke[u]){
            if (chuaxet[v]){
                res.push_back({u, v});
                qe.push(v);
                chuaxet[v] = false;
            }
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
    Tree_BFS(s);
    In();
    return 0;
}