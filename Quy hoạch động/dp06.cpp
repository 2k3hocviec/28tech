#include <bits/stdc++.h>
#define sz 1000001

using namespace std;
using namespace std::chrono;

bool A[sz];
int F[sz];

void san(){
    for (int i = 0; i < sz; ++i){
        A[i] = true;
    }
    A[0] = A[1] = false;
    for (int i = 2; i <= sqrt(sz); ++i){
        if (A[i] == true){
            for (int j = i*i; j < sz; j += i){
                A[j] = false;
            }
        }
    }
}

string multiplyStrings(const string& num1, const string& num2) {
    if (num1 == "0" || num2 == "0") return "0";
    int n = num1.size(), m = num2.size();
    vector<int> res(n + m, 0);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + res[i + j + 1];
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }
    string result;
    int i = 0;
    while (i < res.size() && res[i] == 0) ++i;
    for (; i < res.size(); ++i) result += (res[i] + '0');
    return result;
}

string dem(int n){
    string res = "1";
    for (int i = 2; i <= n; ++i) {
        if(A[i] == true) {
            res = multiplyStrings(res, to_string(i));
        }
    }
    return res;
}

vector <string> dp;

string demdp(int n){
    string res = "1";
    dp.assign(n + 1, "1");
    for (int i = 2; i <= n; ++i) {
        if(A[i] == true) {
            dp[i] = multiplyStrings(dp[i-1], to_string(i));
        }
        else {
            dp[i] = dp[i-1];
        }
    }
    return dp[n];
}

void in(){
    
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = high_resolution_clock::now();
    
    san();
    int t; 
    cin >>t;
    while (t--) {
        int n;
        cin >> n;
        cout << demdp(n) << endl;
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time: " << duration.count() << " ms" << endl;
    return 0;
}