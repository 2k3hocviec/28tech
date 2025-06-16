#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

bool compara(pair <int, int> a, pair <int, int> b) {
    return a.second < b.second;
}

int xuly (vector <pair<int, int>> a) {
    int dem = 0, truoc = 0;
    for (auto it : a) {
        if (truoc < it.first) {
            dem++;
            truoc = it.second;
        }
    }
    return dem;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin >> n;    
    vector <pair <int, int>> a;
    while (n--) {
        pair <int, int> tmp;
        cin >> tmp.first >> tmp.second;
        a.push_back({tmp.first, tmp.second});
    }
    sort(a.begin(), a.end(), compara);
    cout << xuly(a);
    return 0;
}