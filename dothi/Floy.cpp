#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

int a[10][10], n, truyvet[10][10];

void init(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            string str;
            cin >> str;
            if(str == "INF"){
                a[i][j] = INT_MAX;
            }
            else {
                a[i][j] = stoi(str);
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            truyvet[i][j] = i;
            //truyvet[i][j] = j; 
        }
    }
}

vector <int> path = {1};

void tracePath(int u, int v, vector<int>& path) {
    if (truyvet[u][v] == v) {
        path.push_back(v);
        return;
    }
    tracePath(u, truyvet[u][v], path);
    tracePath(truyvet[u][v], v, path);
}

// vector <int> path = {4};
// void pathtrace(int u, int v){
//     path.push_back(truyvet[u][v]);
//     if (truyvet[u][v] == u) return;
//     pathtrace(u, truyvet[u][v]);
// }

void in(){
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cout << a[i][j] << " "; 
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cout << truyvet[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Floy(){
    for (int k = 1; k <= n; ++k){
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= n; ++j){
                if (a[i][j] > a[i][k] + a[k][j] && a[i][k] != INT_MAX && a[k][j] != INT_MAX){
                    a[i][j] = a[i][k] + a[k][j];
                    truyvet[i][j] = truyvet[k][j];
                }
            }
        }
        in();
    }

}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    init();
    Floy(); 
    in();
    tracePath(1, 6, path);
    for (auto it : path) cout << it <<  " ";
    return 0;
}

// 6
// INF 1 INF 4 INF INF
// INF INF 6 2 INF INF
// INF INF INF INF 3 1
// INF INF -3 INF 2 INF
// INF INF INF INF INF INF
// INF INF INF INF -1 INF

