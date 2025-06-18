#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;

int m, n;
vector <int> ke[101];

void Init(){
    cin >> n;
    int i = 1;
    cin.ignore();
    while(i <= n){
        string s; int j;
        getline (cin, s);
        stringstream ss(s);
        while(ss >> j) ke[i].push_back(j);
        ++i;
    }
}

void Print(){
    for(int i = 1; i <= n; ++i){
        sort(ke[i].begin(), ke[i].end());
        for (auto j : ke[i]){
            cout << i << " " << j << endl;
        }
    }
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    Print();
    return 0;
}