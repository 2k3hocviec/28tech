#include <bits/stdc++.h>

using namespace std;

int n, a[20][20];
set <int> ke[20];

void Init(){
    cin >> n ;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n ; ++j){
            cin >> a[i][j];
            if (a[i][j]){
                ke[i].insert(j);
            }
        }
    }
}

void Euler_Path(int u){
    stack <int> S;
    vector <int> dEc;
    S.push(u);
    while (!S.empty()){
        int s = S.top();
        if (!ke[s].empty()){
            int t = *ke[s].begin();
            S.push(t);
            ke[s].erase(t);
        }else {
            dEc.push_back(s);
            S.pop();
        }
    }
    for (auto it = dEc.rbegin(); it != dEc.rend(); ++it){
        cout << *it << " ";
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    Euler_Path(1);
    return 0;
}