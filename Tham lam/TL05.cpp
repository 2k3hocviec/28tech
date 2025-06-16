#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MOD 1000000007
using namespace std;

bool check (vector <int> A) {
    vector <int> tmp = A;
    for (int i = 0; i < tmp.size() / 2; i++) {
        if (A[i] > A[tmp.size() - i - 1]) {
            swap(tmp[i], tmp[tmp.size() - i - 1]);
        }
    }
    sort(A.begin(), A.end());
    return A == tmp;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin >> n;    
    vector <int> A(n);
    while (n--) cin >> A[n];
    cout << check(A);
    return 0;
}