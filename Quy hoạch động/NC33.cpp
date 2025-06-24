#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAX_N = 11;
const int MAX_M = 10000;
const int MOD = 1e9 + 7;

unordered_map<int, vector<int>> transitions;
vector<vector<int>> dp(2, vector<int>(1 << MAX_N, 0));

// Hàm sinh các trạng thái kế tiếp từ mask hiện tại
void generate(int row, int cur_mask, int next_mask, vector<int>& results) {
    if (row == n) {
        results.push_back(next_mask);
        return;
    }

    if (cur_mask & (1 << row)) {
        // ô đã lấp
        generate(row + 1, cur_mask, next_mask, results);
    } else {
        // đặt gạch đứng 2x1
        if (row + 1 < n && !(cur_mask & (1 << (row + 1)))) {
            generate(row + 2, cur_mask, next_mask, results);
        }
        // đặt gạch ngang 1x2
        generate(row + 1, cur_mask, next_mask | (1 << row), results);
    }
}

void precomputeTransitions() {
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> result;
        generate(0, mask, 0, result);
        transitions[mask] = result;
    }
}

int main() {
    cin >> n >> m;
    if ((n * m) % 2 != 0) {
        cout << 0 << endl;
        return 0; // Không thể lấp nếu số ô lẻ
    }

    precomputeTransitions();

    dp[0][0] = 1;
    for (int col = 0; col < m; ++col) {
        fill(dp[(col + 1) % 2].begin(), dp[(col + 1) % 2].end(), 0);
        for (int mask = 0; mask < (1 << n); ++mask) {
            int cur_val = dp[col % 2][mask];
            if (cur_val == 0) continue;
            for (int next_mask : transitions[mask]) {
                dp[(col + 1) % 2][next_mask] = (dp[(col + 1) % 2][next_mask] + cur_val) % MOD;
            }
        }
    }

    cout << dp[m % 2][0] << endl;
    return 0;
}
