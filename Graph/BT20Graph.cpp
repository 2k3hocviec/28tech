#include <bits/stdc++.h>

using namespace std;

set <int> Ke[100];
int n , m, chuaxet[100]; 
vector <pair<int, int>> a;

void Init(){
    cin >> n >> m;
    while (m--){
        int i, j;
        cin >> i >> j;
        a.push_back({i,j});
        Ke[i].insert(j);
        Ke[j].insert(i);
    }
}

void Reset(){
    for (int i = 1; i <= n; ++i) {
        chuaxet[i] = 1;
    }
}

void BFS(int u){
    queue <int> qe; qe.push(u), chuaxet[u] = 0;
    while (!qe.empty()){
        int i = qe.front();
        qe.pop();
        for (auto j : Ke[i]){
            if (chuaxet[j] == 1){
                qe.push(j);
                chuaxet[j] = 0;
            }    
        }
    } 
}

int tplt(){
    int dem = 0; 
    for (int i = 1; i <= n; ++i){
        if(chuaxet[i] == 1){
            dem++;
            BFS(i);
        }
    }
    return dem;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    Reset();
    int cc = tplt();
    for (auto it : a){
        Reset();
        int x = it.first, y = it.second;
        Ke[x].erase(y);
        Ke[y].erase(x);
        if (cc < tplt()){
            cout << x <<  " " << y << endl;
        }
        Ke[x].insert(y);
        Ke[y].insert(x);
    }
    return 0;
}