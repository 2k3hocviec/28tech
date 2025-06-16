#include <bits/stdc++.h>

using namespace std;

int n, k;
set <int> Ke[100];
vector <int> CE;

void Init(){
    cin >> n >> k;
    while (k--){
        int i, j;
        cin >> i >> j;
        Ke[i].insert(j);
    }
}


void Euler_Path(int v){
    stack <int> st;
    st.push(v);
    while (!st.empty()){
        int i = st.top();
        if (!Ke[i].empty()){
            int j = *Ke[i].begin();
            st.push(j);
            Ke[i].erase(j);
            Ke[j].erase(i);
        }
        else{
            CE.push_back(i);
            st.pop();
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Init();
    int v;
    
    Euler_Path(1);
    cout << "Euler_Path: ";
    for (auto it = CE.rbegin(); it != CE.rend(); ++it){
        cout << *it << " ";
    }
    return 0;
}