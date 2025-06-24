#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
int A[100],n,B[100];
string s;
bool final = false;

void in(){
    vector<int> a;
    for (int i = 1; i <= n; ++i){
        if(B[i]) a.push_back(A[i]);
    }    
    if (a.size() > 1 && is_sorted(a.begin(), a.end())){
        for (auto i: a) cout << i << " ";
        cout << endl;
    }
}

void Init() {
    for (int i =1; i<= n; ++i) cin >> A[i];
}

void Try(int i ){
    for (int j = 0; j <= 1; ++j){
        B[i] = j;
        if (i == n) in();
        else Try (i+1);
    }
}

int main()
{
    cin >> n;
    Init();
    Try(1);
    return 0;
}