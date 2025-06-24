#include <iostream>

using namespace std;

int mod = 1e9 + 7;

long long dequy(int n){
    if (n == 0) return 1;
    return (n*dequy(n-1)) % mod;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m; cin >> m;
    while(m--){
        int n; 
        long long result = 1;
        cin >> n;
        for (int i = 1; i <= n; ++i){
            result = (result*i) % mod;
        }
        cout << result << endl;
        cout << dequy(n) << endl;
    }    
    return 0;
}