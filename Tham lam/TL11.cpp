#include <bits/stdc++.h>

using namespace std;

int xuly(string str, int i) {
    int res = 0, mang[256];
    memset(mang, 0, sizeof(mang));
    for (char c : str) {
        mang[c]++;
    }

    priority_queue <int> heap;
    for (int i = 0; i < 256; ++i) {
        if (mang[i] != 0) {
            heap.push(mang[i]);
        }
    }

    while (i != 0) {
        int j = heap.top(); heap.pop();
        heap.push(--j);
        i--;
    }

    while (!heap.empty()) {
        int j = heap.top(); heap.pop();
        res += pow (j, 2);
    }

    return res;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i;
    cin >> i;
    cin.ignore();
    string str;
    cin >> str;
    cout << xuly(str, i);
}