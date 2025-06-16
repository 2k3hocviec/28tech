#include <bits/stdc++.h>

using namespace std;

int n, m, s,t, i, j, chuaxet[100], truoc[100];
vector <int> Ke[100]; 

void Init(){
    cin >> n >> m;
    while(m--){
        cin >> i >> j;
        Ke[i].push_back(j);
        Ke[j].push_back(i);
    }
    for (int i = 1; i <= n; ++i){
        chuaxet[i] = 1;
        sort(Ke[i].begin(), Ke[i].end());
    }
} 

void BFS(int u) {
    queue<int> qe;
    qe.push(u);
    chuaxet[u] = 0; 
    while (!qe.empty()) {
        int j = qe.front();
        qe.pop();
        for (auto i : Ke[j]) {
            if (chuaxet[i] == 1) { 
                chuaxet[i] = 0;    
                qe.push(i);     
            }
        }
    }
}


void ReInit(){
    for (int i = 1; i <= n; ++i) chuaxet[i] = 1;
}

int TPLT(){
    int res = 0;
    for (int i = 1; i <= n; ++i){
        if(chuaxet[i] == 1){
            res++;
            BFS(i);
        }
    }
    return res;
}

void dinh_tru(){
    int cc = TPLT();
    for(int i = 1; i <= n; i++){
        ReInit();
        chuaxet[i] = 0;
        if(cc < TPLT()){
            cout << i << ' ';
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    dinh_tru();
    return 0;
}