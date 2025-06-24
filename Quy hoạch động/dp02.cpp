#include <iostream>
#include <cstring>
#include <chrono>

using namespace std;
using namespace std::chrono;

int memo[100001], mod = 1e9 + 7;

int fibo(int i){
    if (i == 0) return 0;
    if (i == 1) return 1;
    return (fibo(i-1) + fibo(i-2)) % mod;
}

int dp(int i){
    if (i <= 1) return i;
    if (memo[i] != -1) return memo[i];
    memo[i] = (dp(i-1) + dp(i-2)) % mod;
    return memo[i];
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    memset(memo, -1, sizeof(memo));
    int t;
    cin >> t;

    auto start = high_resolution_clock::now();
    while(t--){
        int i; 
        cin >> i;
        cout << dp(i) << endl;
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Time: " << duration.count() << " ms" << endl;

    return 0;
}