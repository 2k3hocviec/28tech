#include <bits/stdc++.h>

using namespace std;

bool check (int n) {
    for (int a = 2; pow(a,3) <= n; ++a) {
        if (n % a == 0) {
            int n1 = n / a;
            for (int b = a + 1; pow(b, 2) <= n1; ++b) {
                if (n1 % b == 0) {
                    int c = n1 / b;
                    if (c > b && c >= 2){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main () {
    int n;
    cin >> n;
    cout << check(n);
    return 0;
}