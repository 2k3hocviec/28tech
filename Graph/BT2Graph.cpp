#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

int m, n;
vector <int> ke[101];
set <pair <int, int>> cnt;

void Init(){
    cin >> n;
    int i = 1;
    cin.ignore();
    while(i <= n){
        string s;
        int j;
        getline (cin, s);
        stringstream ss (s);
        while (ss >>j){
            ke[i].push_back(j);
        }
        i++;
    }
}

void xuly(){
    for (int i = 1; i <= n; ++i){
        for (auto j : ke[i]){
            if (i < j) cnt.insert({i,j});
        }
    }
}

void Print(){
    for (auto i : cnt){
        cout << i.first << " " << i.second << endl;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    xuly();
    Print();
    return 0;
}