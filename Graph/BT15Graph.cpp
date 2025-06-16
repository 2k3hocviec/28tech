#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, s,t, i, j, chuaxet[100], truoc[100];
vector <int> Ke[100]; 

void Init(){
    cin >> n >> m >> s >> t;
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

void BFS(int u){
    queue <int> qe; qe.push(u); chuaxet[u] = 0;
    while (!qe.empty()){
        i = qe.front();
        qe.pop();
        for (auto j : Ke[i]){
            if (chuaxet[j] == 1){
                truoc[j] = i;
                qe.push(j);
                chuaxet[j] = 0;
            }
        }
    }
}

void path(){
    if (truoc[t] == 0){
        cout << "khong co duong di";
    }
    else{
        vector <int> a;
        int u = t;
        while (u != s){
            a.push_back(u);
            u = truoc[u];
        }
        a.push_back(s);
        for (auto it = a.rbegin(); it != a.rend(); ++it){
            cout << *it << " ";
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    BFS(s);
    path();
    return 0;
}