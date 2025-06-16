#include <bits/stdc++.h>

using namespace std;

int n, m, chuaxet[100];
set <int> Ke[100], KeTrans[100];

void Init(){
    cin >> n >> m;
    while(m--){
        int i, j;
        cin >> i >> j;
        Ke[i].insert(j);
        KeTrans[j].insert(i);
    }
}

void DFS(int i){
    chuaxet[i] = 0;
    for (auto j : Ke[i]){
        if (chuaxet[j] == 1){
            DFS(j);
        }
    }
}

void BFS(int i){
    queue <int> qe;
    qe.push(i);
    chuaxet[i] = 00;
    while(!qe.empty()){
        int j = qe.front();
        qe.pop();
        for (auto k : KeTrans[j]){
            if (chuaxet[k] == 1){
                chuaxet[k] = 0;
                qe.push(k);
            }
        }
    }
}

void ReInit(){
    for (int i = 1; i <= n; ++i) chuaxet[i] = 1;
}

bool kiemtra(){
    for (int i = 1; i <= n; ++i){
        if (chuaxet[i] == 1){
            return true;
        }
    }
    return false;
}

bool test(){
    ReInit();
    DFS(1);
    for (int i = 1; i <= n; ++i) {
        if (chuaxet[i] == 1) return false;
    }
    ReInit();
    BFS(1);
    for (int i = 1; i <= n; ++i) {
        if (chuaxet[i] == 1) return false;
    }
    return true;
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    cout << test();

    return 0;
}