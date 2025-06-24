#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n, A[100], B[100], tong = 0;
vector <vector <int>> res;

void Init(){
    for (int i = 1; i <= n; ++i) cin >> A[i];
}

void Try(int i){
    for (int j = 0; j <= 1; ++j){
        B[i] = j;
        tong += B[i]*A[i];
        if (i == n){
            if (tong % 2 == 1){
                vector <int> a;
                for (int k =1; k <= n; ++k){
                    if(B[k]) a.push_back(A[k]);
                }
                res.push_back(a);
            }
        }
        else Try(i+1);
        tong -= B[i]*A[i];
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    Init();
    Try(1);
    sort(res.begin(), res.end());
    for (auto i : res){
        for (auto j  : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}