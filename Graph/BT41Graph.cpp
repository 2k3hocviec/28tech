#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> T;
int d, n, m, parent[100];
queue <vector<int>> hangdoi; 

bool cmp(vector <int> t1, vector <int> t2){
    if (t1[2] == t2[2]){
        if(t1[0] == t2[0]){
            return t1[1] < t2[1];
        }
        else{
            return t1[0] < t2[0]; 
        }
    }
    else{
        return t1[2] < t2[2];
    }
}

void Init(){
    cin >> n >> m;
    vector <vector <int>> tmp;
    while (m--){
        int a, b, c;
        cin >> a >> b >> c;
        tmp.push_back({a, b, c});
    }
    sort(tmp.begin(), tmp.end(), cmp);
    for (auto it : tmp){
        hangdoi.push(it);
    }
}

void ktao(){
    for (int i = 1; i <= n; ++i){
        parent[i] = i;
    }
}

int Find(int u){
    if (u == parent[u]) return u;
    else{
        return parent[u] = Find(parent[u]);
    }
}

bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if (u == v) return false;
    else if (u < v) parent[v] = u;
    else parent[u] = v; 
    return true;
}

void In(){
    if (T.size() < n - 1) {
        cout << "IMPOSSIBLE";
        return;
    }
    for (auto it : T){
        cout << "(" <<it.first << "," << it.second << ") ";
    }
    cout << endl << "tong duong di nho nhat la: " << d;
}

void Kruskal(){
    while (T.size() < n - 1 && !hangdoi.empty()){
        vector <int> e = hangdoi.front();
        hangdoi.pop();
        if (Union(e[0], e[1])){
            T.push_back ({e[0], e[1]});
            d += e[2];
        }
    }
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    ktao();
    Kruskal();
    In();
    return 0;
}