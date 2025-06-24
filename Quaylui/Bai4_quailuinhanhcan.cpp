#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n, m, A[100], B[100], res = 0, dem= 0;
void Init(){
    for (int i = 1; i <= n; ++i) cin >> A[i];
}

void in(){
    for (int i = 1; i <= n; ++i){
        if (B[i]) cout << A[i] << " ";
    }
    cout << endl;
}

void Try(int i){
    dem++;
    for (int j = 0; j <= 1; j++){
        B[i] = j;
        res += A[i]*B[i];
        if (res > m){
            res -= A[i]*B[i];
            continue;
        }
        if (i == n){
            if (res == m)  {
                in();
            }
        }        
        else Try(i+1);
        res -= A[i]*B[i];
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    Init();
    Try(1);
    cout << dem;
    return 0;
}