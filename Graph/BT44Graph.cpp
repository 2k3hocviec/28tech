#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> Ke[100];
int dist[100];
int parent[100], n, m;

void Init(){
    cin >> n >> m;
    while (m--){
        int u, v ,d;
        cin >> u >> v >> d;
        Ke[u].push_back({v, d});
        Ke[v].push_back({u, d});
    }
}

void ReInit(){
    for (int i = 1; i <= n; ++i){
        dist[i] = INT_MAX;
        parent[i] = -1;
    }
}

void Dijkstra(int i){
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> Q;
    dist[i] = 0;
    Q.push({dist[i], i});
    parent[i] = 0;
    while (!Q.empty()){
        int d = Q.top().first, u = Q.top().second;
        Q.pop();
        if (d > dist[u]) continue;
        for (auto it : Ke[u]){
            int v = it.first, kc = it.second;
            if (dist[v] > dist[u] + kc){
                dist[v] = dist[u] + kc;
                parent[v] = u;
                Q.push({dist[v], v});
            }
        }
    }
}

void In(){
    for (int i = 1; i <= n; ++i){
        cout << dist[i] << " ";
    }
}


int main(){
    freopen("input.txt", "r", stdin);      
    freopen("output.txt", "w", stdout);
    Init();
    ReInit();
    Dijkstra(5);
    In();
    return 0;
}