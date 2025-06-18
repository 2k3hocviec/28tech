#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    stack <int> Stack; 
    while(n--){
        string str, word;
        cin >> str;
        if (str == "show"){
            if (Stack.empty()) cout << "EMPTY" << endl;
            else {
                stack <int> tmp = Stack;
                vector <int> S;
                while (!tmp.empty()){
                    S.push_back(tmp.top());
                    tmp.pop();
                }
                for (auto it = S.rbegin(); it != S.rend(); ++it) cout << *it << " ";
                cout << endl;
            }
        }
        else if (str == "push"){
            int i;
            cin >> i;
            Stack.push(i);
        }
    }
    return 0;
}