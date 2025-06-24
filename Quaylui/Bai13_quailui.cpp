#include<bits/stdc++.h>
#include <algorithm>
using namespace std;
int A[100],n,daxet[100], dem;
string s;
bool final = false;

void in(){
    for (int i = 1; i <= n; ++i){
        cout << A[i];
    } 
    cout << endl;
}


void Try(int i) {
    dem++;
    for (int j = 1; j <= n; ++j) {
        if (daxet[j] == 0) { 
            A[i] = j;
            daxet[j] = 1;
            if (i == n && abs(A[i-1] - A[i]) != 1) 
                in();
            else if (i == 1)
                Try(i + 1);
            else if (abs(A[i-1] - A[i]) != 1)  
                Try(i + 1);   
            daxet[j] = 0; 
        }
    }
}

int main()
{
    cin >> n;
    Try(1);
    cout << dem;
    return 0;
}