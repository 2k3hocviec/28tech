#include<bits/stdc++.h>
using namespace std;

int check (int N, int S, int M) {
    int soLuongThucCoTheMua = N * (S - S/7);
    int soLuongCanCo = M * S;
    if (soLuongCanCo > soLuongThucCoTheMua) return -1;
    else {
        return ceil((S*M)/N);
    }
}

int main()
{
    int N, S, M;
    cin >> N >> S >> M;
    cout << check (N, S, M);
    return 0;
}