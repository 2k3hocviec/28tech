#include <iostream>
#include <vector>
#include <iomanip>
#define MAX 10000
using namespace std;

int A[50][50], D[50][50], S[50][50];
int n, u, v;

void Init() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> A[i][j];
            if (i != j && A[i][j] == 0) {
                A[i][j] = MAX;
            }
        }
    }
}

vector <char> c = {'0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','z'};

void Result() {
    cout << "\nTat ca cac cap dinh va duong di ngan nhat:\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                if (D[i][j] >= MAX) {
                    cout << "Khong co duong di tu " << c[i] << " den " << c[j] << ".\n";
                } else {
                    cout << "Duong di ngan nhat tu " << c[i] << " den " << c[j] << ": " << D[i][j] << endl;
                    cout << "Duong di: " << c[i];
                    int current = i;
                    while (current != j) {
                        current = S[current][j];
                        cout << " -> " << c[current];
                    }
                    cout << endl;
                }
            }
        }
    }
}

void Floy() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            D[i][j] = A[i][j];
            if (D[i][j] == MAX) {
                S[i][j] = 0;
            } else {
                S[i][j] = j;
            }
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (D[i][k] != MAX && D[k][j] != MAX && D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    S[i][j] = S[i][k];
                }
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    Floy();
    Result();
    return 0;
}