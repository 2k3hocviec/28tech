#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

struct job {
    int id, deadline, profit;
};

bool compara(job a, job b) {
    return a.profit > b.profit;
}

int xuly (vector <job> A) {
    int loinhuan = 0;
    bool thoigian[A.size()];
    memset(thoigian, false, sizeof(thoigian));
    for (auto it : A) {
        for (int i = it.deadline - 1; i >= 0; --i){
            if (thoigian[i] == false) {
                thoigian[i] = true;
                loinhuan += it.profit;
                break;
            }
        }
    }
    return loinhuan;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin >> n;    
    vector <job> A;

    while (n--) {
        job Job;
        cin >> Job.id >> Job.deadline >> Job.profit;
        A.push_back(Job);
    }
    sort(A.begin(), A.end(), compara);
    cout << xuly(A);
    
    return 0;
}