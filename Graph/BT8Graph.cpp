#include <iostream>
#include <set>
using namespace std;

int n, A[101][101];
set <pair<int,int>> cnt;
void Init(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
             cin >> A[i][j];
            if (A[i][j] != 0 && i < j){
                cnt.insert({i, j});
            }  
        }
    }
}

void Print(){
    for (auto i : cnt) {
        cout << i.first << " " << i.second << " " << A[i.first][i.second]<< endl;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    Print();
    return 0;
}