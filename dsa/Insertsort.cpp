#include <bits/stdc++.h>
using namespace std;

int mang[100], n;

void Init(){
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> mang[i];
}

void Sort(){
    for (int i = 1; i < n; ++i){
        int tmp = mang[i], j;
        for (j = 0; j <= i; ++j){
            if (tmp < mang[j]){
                for (int k = i; k > j; --k) {
                    mang[k] = mang[k-1]; 
                }
                mang[j] = tmp;
                break;
            }
        }     
    }
}

void Sort1(){
    for (int i = 1; i <n; ++i){
        for (int j = i - 1; j >= 0; --j){
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    Sort1();
    In();
    return 0;
}