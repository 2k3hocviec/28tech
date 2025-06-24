#include <bits/stdc++.h>

using namespace std;

int xuly(string a, string b, string c) {
    int x = a.size(), y = b.size(), z = c.size();
    vector<vector<vector<int>>> A(x+1, vector<vector<int>>(y+1, vector<int>(z+1, 0)));
    
    for (int i = 0; i < x; ++i){
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                if (a[i] == b[j] && a[i] == c[k]) {
                    A[i+1][j+1][k+1] = A[i][j][k] + 1;
                }
                else {
                    A[i+1][j+1][k+1] = max({A[i][j+1][k+1], A[i+1][j][k+1], A[i+1][j+1][k]});
                }
            }
        }
    }
    return A[x][y][z];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string a, b, c;
    cin >> a >> b >> c;
    cout << xuly(a,b,c);
    return 0;
}