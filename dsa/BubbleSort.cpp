#include <bits/stdc++.h>
using namespace std;

int mang[100], n;

void Init(){
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> mang[i];
}

void Sort(){
    for (int i = 0; i < n - 1; ++i){
        for (int j = 0; j < n - 1; ++j){
            if (mang[j] > mang[j+1]){
                swap(mang[j], mang[j+1]);
            }
        }
    }
}

void In(){
    for (int i = 0; i < n; ++i) {
        cout << mang[i] << " ";
    }
}

int main(){
    freopen("x.txt", "r", stdin);
    freopen("y.txt", "w", stdout);
    Init();
    Sort();
    In();
    return 0;
}