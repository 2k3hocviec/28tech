#include <bits/stdc++.h>

using namespace std;

int n, k;
set <int> Ke[100], KeTran[100];
vector <int> CE;
int color[100];

void Init(){
    cin >> n >> k;
    while (k--){
        int i, j;
        cin >> i >> j;
        Ke[i].insert(j);
    }
}

void Reset(){
    for (int i = 1; i <= n; ++i) {
        color[i] = 0;
    }
}

bool DFS(int i){
    color[i] = 1;
    for (int j : Ke[i]){
        if (color[j] == 0){
            if (DFS(j)){
                return true;
            }
        }
        else if (color[j] == 1){
            return true;
        }  
    } 
    color[i] = 2;
    return false;     
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    for (int i = 1; i <= n; ++i){
        Reset();
        if (DFS(i)) {
            cout << 1;
            return 1;
        }    
    }
    cout << 0;
    return 0;
}