#include <bits/stdc++.h>

using namespace std;

int mergeAndCount(vector <int>& a, int l, int m, int r) {
    vector<int> left(a.begin() + l, a.begin() + m + 1);
    vector<int> right(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0, count = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (left[i] > right[j]) {
            a[k++] = right[j++];
            count += left.size() - i;
        }
        else {
            a[k++] = left[i++];
        }
    }
    while (i < left.size()) a[k++] = left[i++];
    while (j < right.size()) a[k++] = right[j++];
    return count;
}

int mergeSortAndCount(vector <int>& a, int l, int r) {
    if (l >= r) return 0;
    int m = (r + l) / 2;
    int count = 0;
    count += mergeSortAndCount(a, l, m);
    count += mergeSortAndCount(a, m + 1, r);
    count += mergeAndCount(a, l, m, r);
    return count;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    cout << mergeSortAndCount(A, 0, n-1);
    return 0;
}