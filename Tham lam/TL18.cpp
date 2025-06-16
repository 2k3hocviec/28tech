#include <bits/stdc++.h>

using namespace std;

map <int, int> dem (vector <int> A) {
    map <int, int> res;
    for (auto i : A) {
        res[i]++;
    }
    return res;
}

int numberOfCar(map <int, int> cnt) {
    int res = 0;
    res += min(cnt[3], cnt[1]);
    cnt[3] -= res;
    cnt[1] -= res;
    if (cnt[3] != 0) res += cnt[3];
    res += cnt[4];
    res += cnt[2] / 2;
    if (cnt[2] % 2 == 1) {
        res += 1;
        cnt[1] -= min(2, cnt[1]);   
    } 
    res += ceil(double(cnt[1]) / 4);
    return res;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i;
    cin >> i;
    vector <int> A(i);
    for (int j = 0; j < i; ++j) {
        cin >> A[j];
    }
    map <int, int> a;
    cout << numberOfCar(dem(A));
    return 0;
}