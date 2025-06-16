#include <bits/stdc++.h>

using namespace std;

set <int> V, MST;
int  n, m;
vector <pair <int, int>> T;
vector <pair<int, int>> Ke[100];


void Init(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        V.insert(i);
    }
    while(m--){
        int x, y, a;
        cin >> x >> y >> a;
        Ke[x].push_back({y,a});
        Ke[y].push_back({x,a});
    }
}

void Prim(int s){
    MST.insert(s);
    V.erase(s);
    int d = 0;
    vector <pair <int, int>> T;
    priority_queue < vector <int>, vector<vector <int>>, greater <vector <int>>> Q;
    for (auto it : Ke[s]){
        Q.push({it.second, s, it.first});
    } 
    while(!Q.empty()){
        vector <int> e = Q.top(); Q.pop();
        if (V.find(e[2])!= V.end()){
            d += e[0];
            V.erase(e[2]);
            MST.insert(e[2]);
            T.push_back({e[1], e[2]});
            for (auto it : Ke[e[2]]){
                Q.push({it.second, e[2], it.first});
            }
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    Prim(1);
    return 0;
}