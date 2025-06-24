#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n, k;
int A[100];
char B[100], C[100];
string s;

void Init(){
    for (int i = 1; i <= n; ++i) B[i] = s[i-1];
}

void in(){
    for (int i = 1; i <= k; ++i) cout << s[A[i]-1];
    cout << endl;
}

void Try(int i){
    for (int j = A[i-1]; j <= n; ++j){
        A[i] = j; 
        if (i == k) in();
        else Try (i+1);
    }    
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> k;
    cin >> s;
    A[0] = 1;
    Try(1);
    return 0;
}