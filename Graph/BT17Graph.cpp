#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, s,t, i, j, chuaxet[100], truoc[100];
vector <int> Ke[100]; 

void Init(){
    cin >> n >> m;
    while(m--){
        cin >> i >> j;
        Ke[i].push_back(j);
        Ke[j].push_back(i);
    }
    for (int i = 1; i <= n; ++i){
        chuaxet[i] = 1;
        sort(Ke[i].begin(), Ke[i].end());
    }
}  

void Reset(){
    for (int i = 1; i <= n;++i){
        truoc[i] = 0;
        chuaxet[i] = 1;
    }
}

void BFS(int u){
    queue <int> qe; qe.push(u); chuaxet[u] = 0; 
    while(!qe.empty()){
        i = qe.front();
        qe.pop();
        for (auto j : Ke[i]){
            if (chuaxet[j] == 1){
                qe.push(j);
                chuaxet[j] = 0;
                truoc[j] = i;
            }
        }
    }
}

void path(){
    if (truoc[t] == 0){
        cout << "khong co duong di";
    }
    else{
        int u = t;
        vector <int> a;
        while (u != s){
            a.push_back(u);
            u = truoc[u];
        }
        a.push_back(s);
        for (auto it = a.rbegin(); it != a.rend(); ++it){
            cout << *it << " ";
        }
    }
    cout << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    int k;
    cin >> k;
    while(k--){
        cin >> s >> t; 
        Reset();
        BFS(s);
        path();
    }
    return 0;
}