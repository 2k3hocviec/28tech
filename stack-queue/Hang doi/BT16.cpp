#include <iostream>
#include <queue>
using namespace std;

// đường đi của quân mã.
int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
int mang[9][9];
int daxet[9][9];
pair <int, int> parent[9][9];

char kitu (int c) {  
    return c + 'a' - 1;
}

char kituso(int c) {
    return c + '0';
}

void pathKnight(pair <int, int> Start, pair <int, int> End) {
    queue <pair <int, int>> Queue;
    int step[9][9] = {};
    Queue.push({Start.first, Start.second});
    daxet[Start.first][Start.second] = 1;
    step[Start.first][Start.second] = 0;
    while (!Queue.empty()) {
        pair <int, int> tmp = Queue.front();
        Queue.pop();
        int i = tmp.first, j = tmp.second;
        if (i == End.first && j == End.second) {
            cout << step[i][j] << endl;
            return;
        }
        for (int k = 0; k < 8; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x > 0 && x <= 8 && y > 0 && y <= 8 && daxet[x][y] == 0) {
                daxet[x][y] = 1;
                step[x][y] = step[i][j] + 1;
                parent[x][y] = {i, j};
                Queue.push({x, y});
            }
        }
    }   
}

void truyvet(pair <int, int> Start, pair <int, int> End) {
    vector <pair <int, int>> res;
    pair <int, int> tmp = End;
    while (tmp != Start) {
        res.push_back(tmp);
        tmp = parent[tmp.first][tmp.second];
    }
    res.push_back(Start);
    for (int i = res.size() - 1; i >= 0; --i) {
        cout << res[i].first << res[i].second << " ";
    }
    cout << endl;
} 

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b, c ,d;
    cin >> a >> b >> c >> d;
    pathKnight({a, b}, {c, d});
    truyvet({a, b}, {c, d});
    return 0;
}