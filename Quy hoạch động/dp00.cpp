#include <iostream>
#include <cstring>
#include <chrono>

using namespace std;
using namespace std::chrono;

int memo[1000], cost[1000], n;

int dp(int i){
    if (i <= 1) {
        return 0;
    }
    if (memo[i] != -1){
        return memo[i];
    }
    memo[i] = min(dp(i - 1) + cost[i - 1], dp(i - 2) + cost[i - 2]);
    return memo[i];
}

int dequy(int i){
    if (i <= 1) {
        return 0;
    }
    return min(dequy(i-1) + cost[i-1], dequy(i-2) + cost[i-2]);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    memset(memo, -1, sizeof(memo));
    cin >> n; 
    for (int i = 0; i < n; ++i) cin >> cost[i];

    auto start = high_resolution_clock::now();
    cout << dp(5) << endl;
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time: " << duration.count() << " ms" << endl;
    
    
    return 0;
}