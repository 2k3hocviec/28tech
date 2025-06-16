#include <bits/stdc++.h>
using namespace std;

int A[100], n;

void Init(){
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];
}

void In(){
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
}

void Merge(int left, int mid, int right){
    vector <int> B;
    int p1 = left, p2 = mid+1;
    while (p1 <= mid && p2 <= right){
        if (A[p1] < A[p2]){
            B.push_back(A[p1++]);
        }
        else{
            B.push_back(A[p2++]);
        }
    }
    while (p1 <= mid){
        B.push_back(A[p1++]);
    }
    while (p2 <= right){
        B.push_back(A[p2++]);
    }
    for (int i = left, j = 0; i <= right; ++i, ++j){
        A[i] = B[j];
    }
}

void MergeSort(int left, int right){
    if(left < right){
        int mid = (left+right)/2; 
        MergeSort(left, mid);
        MergeSort(mid+1, right);
        Merge(left, mid, right);
    }
}

int main(){
    freopen("x.txt", "r", stdin);
    freopen("y.txt", "w", stdout);
    Init();
    MergeSort(0, n - 1);
    In();
    return 0;
}