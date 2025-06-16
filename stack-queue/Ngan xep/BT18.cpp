#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector <int> res (100,-1), A(100);

void xuly(vector <int> A){
    stack <int> st;
    for (int i = 0; i < A.size(); ++i){
        while (!st.empty() && A[i] > A[st.top()]){
            res[st.top()] = A[i + 1];
            st.pop();
        }
        st.push(i);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];
    xuly(A);
    for (int i = 0; i < n; ++i) cout << res[i] << " ";
    return 0;
}