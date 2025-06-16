#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

/*Cách hoạt động:

Duyệt từng cột, dùng stack lưu chỉ số các cột tăng dần.
Khi gặp cột thấp hơn, tính diện tích với chiều cao là cột vừa bị pop khỏi stack.
Kết quả là diện tích lớn nhất tìm được.
*/
int maxArea(vector <int> A){
    int res = 0;
    A.push_back(0);
    int n = A.size();
    stack <int> st;

    for (int i = 0; i < n; ++ i){
        while (!st.empty() && A[i] < A[st.top()]){
            int h = A[st.top()]; st.pop();
            int d = st.empty() ? i : i - st.top() - 1;
            
            res = max(res, d*h);
        }
        st.push(i);
    }
    return res;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; 
    cin >> n;
    vector <int> A;
    for (int i = 0; i < n; ++i){
        int j; cin >> j;
        A.push_back(j);
    }
    cout << maxArea(A);
    return 0;
}