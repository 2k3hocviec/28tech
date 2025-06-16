#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n, m;
// vector <pair <pair <int, int>, int>> a;
int d[100];
int truoc[100];
int A[100][100];

// void Init(){
//     cin >> n >> m;
//     while (m--){
//         int u, v, w;
//         cin >> u >> v >> w;
//         a.push_back({{u, v}, w});
//         a.push_back({{v, u}, w});
//     }
// }

void init(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            string str;
            cin >> str;
            if(str == "INF"){
                A[i][j] = INT_MAX;
            }
            else {
                A[i][j] = stoi(str);
            }
        }
    }
}

// void ReInit(){
//     for (int i = 1; i <= n; ++i){
//         for (int j = 1; j <= n; ++j){
//             A[i][j] = INT_MAX;
//         }
//     }
//     for (auto it : a){
//             int u = it.first.first, v = it.first.second, kc = it.second;
//             A[u][v] = kc;
//     }        
//     for (int i = 1; i <= n; ++i) {
//         d[i] = INT_MAX;
//         truoc[i] = -1;
//     }
// }
// chỉ đúng lý thuyết thực tế thực hiện lại sai
// void Bellman_Ford1(int s){
//     ReInit();
//     d[s] = 0;
//     truoc[s] = 0;
//     for (int i = 1; i <= n - 1; ++i){
//         for (auto it : a){
//             int u = it.first.first, v = it.first.second, kc = it.second;
//             if (d[v] > d[u] + kc){
//                 d[v] = d[u] + kc;
//                 truoc[v] = u;
//             }
//         }
//     }
// }

void Bellman_Ford2(int s){
    for (int i = 1; i <= n; ++i){
        d[i] = A[s][i];
        truoc[i] = s;
    }
    d[s] = 0;
    for (int i = 1; i <= n - 2; ++i){
        for (int v = 1; v <= n; ++v){
            if (v != s){
                for (int u = 1; u <= n; ++u){
                    if (d[u] == INT_MAX || A[u][v] == INT_MAX) continue;
                    if (d[v] > d[u]+ A[u][v]){
                        d[v] = d[u] + A[u][v];
                        truoc[v] = u;
                    }
                }
            }
        }
    }
}


int main(){
    freopen("input.txt", "r", stdin);      
    freopen("output.txt", "w", stdout);
    init();
    Bellman_Ford2(1);
    for (int i = 1 ; i <= n; ++i){
        cout << d[i] << " " << truoc[i] << endl;
    }
    return 0;
}

