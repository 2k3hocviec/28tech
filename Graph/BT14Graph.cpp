#include <bits/stdc++.h>
using namespace std;

int n, m, s, t, dadiqua[100], truoc[100];
vector<int> Ke[101];

void Init() {
    cin >> n >> m >> s >> t;
    while (m--) {
        int i, j;
        cin >> i >> j;
        Ke[i].push_back(j);
        Ke[j].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        sort(Ke[i].begin(), Ke[i].end());
    }
}

void dfs(int u){
    dadiqua[u] = 1;
    for (auto i : Ke[u]){
        if (dadiqua[i] == 0){
            truoc[i] = u;
            dfs(i);
        }
    }
}

void path(){
    if (truoc[t] == 0){
        cout << "khong co duong di";
    }
    else{
        vector <int> a;
        int j = t;
        while(j != s){
            a.push_back(j);
            j = truoc[j];
        }
        a.push_back(s);
        for (auto it = a.rbegin(); it != a.rend(); ++it){
            cout << *it << " ";
        }
    }
}


int main() {
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    Init();
    dfs(s);
    path();
    return 0;
}