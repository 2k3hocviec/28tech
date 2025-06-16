#include <bits/stdc++.h>

using namespace std;

string multiplyStrings(const string& num1, const string& num2) {
    bool neg1 = (!num1.empty() && num1[0] == '-');
    bool neg2 = (!num2.empty() && num2[0] == '-');
    string a = neg1 ? num1.substr(1) : num1;
    string b = neg2 ? num2.substr(1) : num2;

    if (a == "0" || b == "0") return "0";
    int n = a.size(), m = b.size();
    vector<int> res(n + m, 0);
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + res[i + j + 1];
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }
    string result;
    int i = 0;
    while (i < res.size() && res[i] == 0) ++i;
    for (; i < res.size(); ++i) result += (res[i] + '0');
    if ((neg1 ^ neg2) && result != "0") result = "-" + result;
    return result;
}

string compare(const string& a, const string& b) {
    // Kiểm tra dấu âm
    bool negA = (!a.empty() && a[0] == '-');
    bool negB = (!b.empty() && b[0] == '-');
    string sa = negA ? a.substr(1) : a;
    string sb = negB ? b.substr(1) : b;

    // Nếu khác dấu
    if (negA && !negB) return b;
    if (!negA && negB) return a;

    // Cùng dấu
    int cmp = 0;
    if (sa.size() > sb.size()) cmp = 1;
    else if (sa.size() < sb.size()) cmp = -1;
    else {
        for (int i = 0; i < sa.size(); ++i) {
            if (sa[i] > sb[i]) { cmp = 1; break; }
            if (sa[i] < sb[i]) { cmp = -1; break; }
        }
    }
    // Nếu là số âm thì đảo ngược kết quả
    if (negA && negB) cmp = -cmp;
    return cmp >= 1 ? a : b;
}

string ketQuaLonNhat(vector <int> a) {
    int n = a.size();
    sort(a.begin(), a.end());
    string res = "0", x, y, z, t;
    if (n <= 1) return res;
    if (n >= 2) {
        x = multiplyStrings(to_string(a[0]), to_string(a[1]));
        y = multiplyStrings(to_string(a[a.size()- 1]), to_string(a[a.size()-2]));
        res = compare(res, x);
        res = compare(res, y);
    }
    if (n >= 3) { 
        z = multiplyStrings(multiplyStrings(to_string(a[0]), to_string(a[1])), to_string(a[a.size() - 1]));
        t = multiplyStrings(multiplyStrings(to_string(a[a.size() - 3]), to_string(a[a.size() - 2])), to_string(a[a.size() - 1]));
        res = compare(res, z);
        res = compare(res, t);
    }
    return res;
}

long long useLongLong(vector <int> a) {
    long long res = LLONG_MIN;
    sort(a.begin(), a.end());
    if (a.size() == 1) return (long long)a[0];
    res = max(res, (long long)a[0]* (long long)a[1]);
    res = max(res, (long long)a[a.size() - 1]* (long long)a[a.size() - 2]);
    if (a.size() > 2) {
        res = max(res, (long long)a[0] * (long long)a[1] * (long long)a[a.size() - 1]);
        res = max(res, (long long)a[a.size() - 1] * (long long)a[a.size() - 2] * (long long)a[a.size() - 3]);
    }
    return res;
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i;
    cin >> i;
    vector <int> A(i);
    for (int j = 0; j < i; ++j) {
        cin >> A[j];
    }
    cout << ketQuaLonNhat(A) << endl;
    cout << useLongLong(A) << endl;
    return 0;
}