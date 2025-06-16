#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <int> A(n), res(n, -1);
    for (int i = 0; i < n; ++i) cin >> A[i];
    stack <int> st;
    for (int i = 0; i < n; ++i){
        while (!st.empty() && A[i] > A[st.top()]){
            res[st.top()] = A[i];
            st.pop();
        }
        st.push(i);
    }
    for (auto it : res) cout << it << " ";
    return 0;
}