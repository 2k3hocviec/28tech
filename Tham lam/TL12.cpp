#include <bits/stdc++.h>

using namespace std;

void minLuckyNumber(int n) {
    int x, y, leng = INT_MAX;
    for (int i = 0; i <= n/7; ++i) {
        int j = n - 7*i;
        if (j % 4 == 0){
            j /= 4;
            if (i + j < leng) {
                leng = i + j;
                x = j;
                y = i;
            }
        }
    }
    if (x==-1) cout << -1 << endl;
    else cout << x << " " << y << endl;
}

int main () {
    int i; 
    cin >> i;
    minLuckyNumber(i);
    return 0;
}