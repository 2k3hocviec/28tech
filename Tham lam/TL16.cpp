#include<bits/stdc++.h>
using namespace std;

vector<pair <int,int>> xuly (int i, int j) {
    vector<pair <int,int>> cnt;
    while (i != 0){
        int tmp = ceil(double(j)/i);
        cnt.push_back({1,tmp});
        int x = i*tmp - j;
        int y = j*tmp;
        int g = gcd(x,y);
        i = x / g;
        j = y / g;
    }
    return cnt;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i, j;
    cin >> i >> j;
    vector<pair <int,int>> tmp = xuly(i, j);
    for (auto it : tmp) cout << it.first << " " << it.second << endl;
    return 0;
}