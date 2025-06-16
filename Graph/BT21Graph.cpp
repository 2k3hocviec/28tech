#include <bits/stdc++.h>

using namespace std;

int n, k;
set <int> Ke[100];
vector <int> CE;
int chuaxet[100];
int parent[100];

void Init(){
    cin >> n >> k;
    while (k--){
        int i, j;
        cin >> i >> j;
        Ke[i].insert(j);
        Ke[j].insert(i);
    }
    for (int i = 1; i <= n; ++i) chuaxet[i] = 1;
}

bool DFS(int i){
    chuaxet[i] = 0;
    for (auto j : Ke[i]){
        if (chuaxet[j] == 1){
            parent[j] = i;
            return DFS(j); 
        }    
        else if (parent[j] != i) return true;
    }
    return false;        
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    for (int i = 1; i <= n; ++i){
        if (DFS(i)) {
            cout << 1;
            return 1;
        }    
    }
    cout << 0;
    return 0;
}