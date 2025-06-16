#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

int m, n;
vector <int> ke[101];
int A[101][101];
set <pair <int, int>> cnt;

void Init(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> A[i][j];
            if (A[i][j]){
                ke[i].push_back(j);
            }
        }
    }
}

void Print(){
    for(int i = 1; i <= n; ++i){
        sort(ke[i].begin(), ke[i].end());
        for (auto j : ke[i]){
            cout << i << " " << j << endl;
        }
    }
}

void xuly(){
    for (int i = 1;i <= n; ++i){
        for (auto j : ke[i]){
            if (i < j) cnt.insert({j, i});
        }
    }
}

void Print1(){
    for (auto i : cnt) 
        cout << i.first << " " << i.second << endl;
}

void Print2(){
    for (int i = 1; i <= n; ++i){
        cout << i << " : " ;
        for (auto j : ke[i]){
            cout << j << " ";
        }
        cout << endl;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    xuly();
    Print1();
    Print2();
    return 0;
}