#include <iostream>
#include <vector>
#include <algorithm>
#include  <queue>

using namespace std;

int n, m, s;
vector <int> Ke[11];
int dadiqua[11];

void Init(){
    cin >> n >> m;
    while(m--){
        int i, j;
        cin >> i >> j;
        Ke[i].push_back(j);
        Ke[j].push_back(i);
    }
    for (int i = 1; i <= n; ++i){
        sort(Ke[i].begin(), Ke[i].end());
    }
}

void DFS(int s){
    dadiqua[s] = 1;
    for (auto i : Ke[s]){
        if (dadiqua[i] == 0){
            DFS(i);
        }
    }
}

void duyet_TPLT(){
    int solt = 0;
    for (int u = 1; u <= n; ++u){
        if(dadiqua[u] == 0){
            ++solt;
            DFS(u);
        }
    }
    cout << solt;
}

int main (){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    duyet_TPLT(); 
    return 0;
}