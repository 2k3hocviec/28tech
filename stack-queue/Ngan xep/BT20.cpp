#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxHistogram(vector<int>& A) {
    int res = 0;
    A.push_back(0);
    int n = A.size();
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && A[i] < A[st.top()]) {
            int h = A[st.top()]; st.pop();
            int d = st.empty() ? i : i - st.top() - 1;
            res = max(res, h * d);
        }
        st.push(i);
    }
    return res;
}

int maximalRectangle(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;
    int n = matrix.size(), m = matrix[0].size();
    vector<int> height(m, 0);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1) height[j]++;
            else height[j] = 0;
            cout << height[j] << " ";
        }
        cout << endl;
        res = max(res, maxHistogram(height));
        cout << res << endl;
    }
    return res;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];
    cout << maximalRectangle(matrix);
    return 0;
}