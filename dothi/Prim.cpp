#include <bits/stdc++.h>

using namespace std;

set <int> V, MST, Vh;
int  n, m;
vector <pair <int, int>> T;
vector <pair<int, int>> Ke[100];
vector <vector <int>> E;
int parent[20];

void Init(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        V.insert(i);
    }
    while(m--){
        int x, y, a;
        cin >> x >> y >> a;
        Ke[x].push_back({y,a});
        Ke[y].push_back({x,a});
    }
}

bool cmp(vector <int>& a, vector <int>& b){
    if (a[2] == b[2]){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        else{
            return a[0] < b[0];
        }
    }
    else {
        return a[2] < b[2];
    }
}

void Init1(){
    cin >> n >> m;
    while (m--){
        int x, y , d;
        cin >> x >> y >> d;
        E.push_back({x,y,d});
    }
    sort(E.begin(), E.end(), cmp);
    for (int i = 1; i <= n; ++i){
        parent[i] = i;
    }
}

void Prim(int s){
    MST.insert(s);
    V.erase(s);
    vector <pair <int,int>> T;
    int d = 0;
    priority_queue <vector <int>, vector <vector <int>>, greater <vector <int>>> Q;
    for (auto it : Ke[s]){
        Q.push({it.second, s, it.first});
    }
    while (!Q.empty()){
        vector <int> e = Q.top();
        Q.pop();
        if (V.find(e[2]) != V.end()){
            d += e[0];
            MST.insert(e[2]);
            V.erase(e[2]);
            T.push_back({e[1], e[2]});
            for (auto it : Ke[e[2]]){
                Q.push({it.second, e[2], it.first});
            }
        }
    }
    for (auto it : T) cout << it.first << " " << it.second << endl;
    cout << d;
}

void Prim1(int s){
    Vh.insert(s);
    V.erase(s);
    vector <pair <int,int>> T;
    int chiphi = 0;
    while (!V.empty() && !E.empty()) {
        bool found = false;
        for (auto it = E.begin(); it != E.end(); ++it) {
            if (Vh.count((*it)[0]) && V.count((*it)[1])) {
                chiphi += (*it)[2];
                T.push_back({(*it)[0], (*it)[1]});
                V.erase((*it)[1]);
                Vh.insert((*it)[1]);
                found = true;
                break;
            }
            if (Vh.count((*it)[1]) && V.count((*it)[0])) {
                chiphi += (*it)[2];
                T.push_back({(*it)[0], (*it)[1]});
                V.erase((*it)[0]);
                Vh.insert((*it)[0]);
                found = true;
                break;
            }
        }
        if (!found) break; // Không còn cạnh hợp lệ để chọn
    }
    cout << chiphi;
    cout << endl;
    for (auto it : T) cout << it.first << " " << it.second << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    Prim(3);
    return 0;
}