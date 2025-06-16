#include <bits/stdc++.h>
using namespace std;

void In(vector<int> &A, int n){
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
}

void Heapify(int i, int n, vector <int> &A){
    int left = 2*i + 1, right = 2*i + 2, root = i;
    if (left < n && A[left] > A[root]) root = left;
    if (right < n && A[right] > A[root]) root = right;
    if (root != i) {
        swap (A[i], A[root]);
        Heapify(root, n, A);
    }
} 

void Sort(int n, vector <int> &A){
    for (int i = n/2 - 1; i>= 0; --i) Heapify(i, n, A);
    for (int i = n - 1; i >= 0; i--){
        swap (A[0], A[i]);
        Heapify(0,i,A);
    }
}


int main(){
    freopen("x.txt", "r", stdin);
    freopen("y.txt", "w", stdout);
    int n; cin >> n; 
    vector<int> A(n);
    for (int i = 0; i <= n; ++i) cin >> A[i];
    Sort(n, A);
    In(A,n);
    return 0;
}