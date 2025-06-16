#include <bits/stdc++.h>

using namespace std;

int M, N, A[100][100];
int dem[100][100];
bool daxet[100][100];

void BFS() {
    queue <pair <int, int>> Queue;
    Queue.push({1, 1});
    dem[1][1] = 1;
    while (!Queue.empty()) {
        pair <int, int> tmp = Queue.front(); Queue.pop();
        int i = tmp.first, j = tmp.second;
        if (j + A[i][j] > 0 && j + A[i][j] <= N) 
            Queue.push({i, j + A[i][j]});
        dem[i][j + A[i][j]] += dem[i][j];
         
        if (i + A[i][j] > 0 && i + A[i][j] <= M) 
            Queue.push({i + A[i][j], j});
        dem[i + A[i][j]][j] += dem[i][j];;
        
    } 
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> M >> N;
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> A[i][j];
        }
    }
    BFS();
    cout << dem[M][N];
    return 0;
}