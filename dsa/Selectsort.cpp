#include <bits/stdc++.h>
using namespace std;

int mang[100], n;

void Init(){
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> mang[i];
}

void In(){
    for (int i = 0; i < n; ++i) {
        cout << mang[i] << " ";
    }
}

void Sort(){
    for (int i = 0; i < n - 1; ++i){
        int vitri = i, nho = INT_MAX;
        for (int j = i; j < n; ++j){
            if (mang[j] < nho){
                vitri = j;
                nho = mang[j];
            }
        }
        swap(mang[i], mang[vitri]);
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