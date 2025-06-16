#include<bits/stdc++.h>
using namespace std;

string check (int S, int D) {
    if (ceil((double)S / 9) > D) {
        return "-1";
    }    
    string res;
    while(S > 9){
        res = "9" + res;
        S -= 9;
    }
    if (S != 0 && res.size() == D-1) res = to_string(S) +res;
    else {
        res = to_string(S-1) + res;
        while (res.size() < D){
            res = "0" + res;
        }
        res = "1" + res;
    } 
    return res;
}

int main()
{
    int S, D;
    cin >> S >> D;
    cout << check(S,D);
    return 0;
}