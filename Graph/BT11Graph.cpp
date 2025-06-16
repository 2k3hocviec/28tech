#include <iostream>
#include <vector>
#include <algorithm>
#include  <queue>

using namespace std;

int n, m, s;
vector <int> Ke[100];
int dadiqua[100];

void Init(){
    cin >> n >> m;
    while(m--){
        int i, j;
        cin >> i >> j;
        Ke[i].push_back(j);
        Ke[j].push_back(i);
    }
    for (int i = 1; i <= n; ++i){
        sort(Ke[i].begin(), Ke[i].end());
    }
}

void BFS(int s){
    queue <int> qe; qe.push(s); dadiqua[s] = 1;
    while (!qe.empty()){
        int i = qe.front();
        cout << i << " ";
        qe.pop();
        for(auto j : Ke[i]){
            if(dadiqua[j] == 0){
                qe.push(j);
                dadiqua[j] = 1;
            }
        }
    }
}

int main (){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    BFS(1); 
    return 0;
}