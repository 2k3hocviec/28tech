#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int xuly(vector <int> A) {
    if (A[0] == 1) return 0;
    int l = 0, r = A.size() - 2, res = A.size() - 1;
    while (l <= r) {
        int  mid = (l + r) / 2;
        if (A[mid] != A[mid+1]){
            res = mid;
            break;
        }
        else if (A[mid] == 0 && A[mid + 1] == 0) {
            l = mid + 1;
        }
        else if (A[mid] == 1 && A[mid + 1] == 1) {
            r = mid - 1;
            res = mid;
        }
    }
    return res + 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    auto start = chrono::high_resolution_clock::now();
    
    cout << xuly(A) << endl;

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;
    cout << "Time: " << elapsed.count() << " ms" << endl;
    
    return 0;
}