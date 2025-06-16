#include <iostream>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int n, a[20][20];
set <int> ke[20];

void Init(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
            if (a[i][j]) {
                ke[i].insert(j);
            }
        }
    }
}

void init_ke(){
    cin >> n;
    int m; cin >> m;
    while(m--){
        int i, j; 
        cin >> i >> j;
        ke[i].insert(j);
    }
}

void Euler_Cycle(int u){
    stack <int> S;
    vector <int> CE;
    S.push(u);
    while(!S.empty()){
        int s = S.top();
        if (!ke[s].empty()){
            int t = *ke[s].begin();
            S.push(t);
            ke[s].erase(t);
        }
        else{
            S.pop();
            CE.push_back(s);
        }
    }
    for (auto it = CE.rbegin(); it != CE.rend(); ++it) {
        cout << *it << " ";
    }
}

void vohuong(int u){
    stack <int> S;
    S.push(u);
    vector <int> dCE;
    while (!S.empty()){
        int i = S.top();
        if(!ke[i].empty()){
            int j = *ke[i].begin();
            ke[i].erase(j);
            ke[j].erase(i);
            S.push(j);
        }
        else{
            S.pop();
            dCE.push_back(i);
        }
    }
    for (auto it = dCE.rbegin(); it != dCE.rend(); ++it) {
        cout << *it << " ";
    }
}

int main(){
    freopen("input.txt", "r", stdin);      
    freopen("output.txt", "w", stdout);
    Init();
    vohuong(4);
    return 0;
}

// 8 18
// 1 2
// 1 3
// 2 3 
// 2 4 
// 2 5
// 3 7
// 3 8
// 4 6
// 4 7
// 5 6
// 5 8
// 6 4 
// 6 8
// 7 1
// 7 2
// 8 1
// 8 2
// 8 5

// 6
// 0 1 1 0 0 0
// 1 0 1 0 0 0
// 1 1 0 1 1 0
// 0 0 1 0 1 1
// 0 0 1 1 0 1
// 0 0 0 1 1 0

// 6
// 0 1 0 0 0 1
// 0 0 1 0 0 0
// 1 0 0 1 0 0
// 0 0 0 0 1 0
// 0 0 0 0 0 1
// 1 0 0 0 0 0