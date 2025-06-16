#include <iostream>

using namespace std;

int n, m, A[1001][1001];

void Init(){
    cin >> n >> m;
    while(m--){
        int i, j;
        cin >> i >> j;
        A[i][j] = 1;
        A[j][i] = 1;
    }
}

void Print(){
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cout << A[i][j] << " ";
        }
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