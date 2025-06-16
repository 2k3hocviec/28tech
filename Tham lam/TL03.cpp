#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MOD 1000000007
using namespace std;

int res(vector <int> A) {
    long long tong = 0;
    for (int i = 0; i < A.size(); ++i) {
        tong = (tong + ((A[i] * i) % MOD)) % MOD;
    }
    return tong;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin >> n;    
    vector <int> A(n);
    while (n--) cin >> A[n];
    sort(A.begin(), A.end());
    cout << res(A);
    return 0;
}