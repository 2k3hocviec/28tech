#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, s;
vector <int> Ke[11];
int dadiqua[11];

void Init(){
    cin >> n >> m >> s;
    while(m--){
        int i, j;
        cin >> i >> j;
        Ke[i].push_back(j);
        Ke[j].push_back(i);
    }
}

void DFS(int s){
    dadiqua[s] = 1;
    cout << s << " ";
    sort(Ke[s].begin(), Ke[s].end());
    for (auto i : Ke[s]){
        if(!dadiqua[i]){
            DFS(i);
        }
    }
}

int main (){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    DFS(s); 
    return 0;
}