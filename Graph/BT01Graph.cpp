#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m; 
vector <int> ke[1001];

void Init(){
    cin >> n >> m;
    while(m--){
        int i, j;
        cin >> i >> j;
        ke[i].push_back(j);
        ke[j].push_back(i);
    }
}

void Print(){
    for (int i = 1; i <= n; ++i){
        sort(ke[i].begin(), ke[i].end());
        cout << i << " : ";
        for (auto j : ke[i]) cout << j << " "; 
        cout << endl;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    Print();
    return 0;
}