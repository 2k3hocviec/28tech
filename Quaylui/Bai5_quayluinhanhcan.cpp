#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n, m, A[100][100], dadi[100][100], res = 0, dem= 0;
void Init(){
    for (int i = 1; i <= n; ++i){
        for (int j =1; j <= n; ++j){
            cin >> A[i][j];
        }
    }
}

void Try(int i, int j){
    if (i == n && j == m){
        dem++;
    }
    if (i+1 <= n && dadi[i+1][j] == 0){
        dadi[i+1][j] = 1;
        Try(i+1, j);
        dadi[i+1][j] = 0;
    }
    if (j+1 <= m && dadi[i][j+1] == 0){
        dadi[i][j+1] = 1;
        Try(i, j+1);
        dadi[i][j+1] = 0;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    Init();
    Try(1,1);
    cout << dem;
    return 0;
}