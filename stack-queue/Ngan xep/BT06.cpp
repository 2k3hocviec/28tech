#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string xuly(string str, int k){
    for (int i = 0; i < str.size() - k;){
        bool check = true;
        for (int j = i + 1; j < i + k; ++j) {
            if (str[i] != str[j]){
                check = false;
                break;
            }
        }
        if (check == true){
            str.erase(i, k);
        }
        else i++;
    }
    return str;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    int i;
    cin >> i;
    cout << xuly(str, i);
    return 0;
}