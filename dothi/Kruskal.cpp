#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> T;
int d, n, m, parent[100], a[100][100];
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

void init(){
    cin >> n;
    vector <vector<int>> tmep;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            string str;
            cin >> str;
            if(str == "INF"){
                a[i][j] = INT_MAX;
            }
            else {
                a[i][j] = stoi(str);
                tmep.push_back({i,j,a[i][j]});
            }
        }
    }
    sort(tmep.begin(),tmep.end(), cmp);
    for (auto it : tmep){
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
    init();
    ktao();
    Kruskal();
    In();
    return 0;
}

// 12
// 0 2 3 INF INF INF ING INF 2 INF INF INF
// 2 0 5 INF 2 2 INF 2 2 INF INF 6
// 3 5 0 2 6 INF INF INF INF INF INF INF
// INF INF 2 0 3 INF INF INF INF INF 4 INF
// INF 2 6 3 0 2 INF INF INF INF INF INF
// INF 2 INF INF 2 0 1 1 INF INF INF INF
// INF INF INF INF INF 1 0 1 INF 3 INF INF
// INF 2 INF INF INF 1 1 0 1 1 INF INF
// 2 2 INF INF INF INF INF 1 0 1 INF INF
// INF INF INF INF INF INF 3 1 1 0 5 3
// INF INF INF 4 INF INF INF INF INF 5 0 INF
// INF 6 INF INF INF INF INF INF INF 3 INF 0


