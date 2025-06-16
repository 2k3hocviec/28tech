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

void Sort(int left, int right){
    int i = left, j = right, mid = mang[(right + left)/2];
    while (i <= j){
        while (mang[i] < mid) i++;
        while (mid < mang[j]) j--;
        if (i <= j) {
            swap(mang[i], mang[j]);
            i++;
            j--;
        }    
    }
    if (left < j) Sort(left, j);
    if (i < right) Sort(i, right);
}

int main(){
    freopen("x.txt", "r", stdin);
    freopen("y.txt", "w", stdout);
    Init();
    Sort(0, n - 1);
    In();
    return 0;
}