#include <iostream>
#include <cstring>
#include <cmath>
#include <chrono>
#define sz 1000001

using namespace std;
using namespace std::chrono;

bool A[sz];
int F[sz];

void san(){
    for (int i = 0; i < sz; ++i){
        A[i] = true;
    }
    A[0] = A[1] = false;
    for (int i = 2; i <= sqrt(sz); ++i){
        if (A[i] == true){
            for (int j = i*i; j < sz; j += i){
                A[j] = false;
            }
        }
    }
}

void dem(){
    for (int i = 1; i < sz; ++i){
        if(A[i] == true){
            F[i] = F[i-1] + 1;
        }
        else{
            F[i] = F[i-1];
        }
    }
}

void in(){
    for (int i = 1; i < sz; ++i){
        cout << F[i] << endl;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = high_resolution_clock::now();
    
    san();
    dem();

    int t; 
    cin >> t;
    while (t--){
        int i; 
        cin >> i;
        cout << F[i] << endl;
    }


    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Time: " << duration.count() << " ms" << endl;
    return 0;
}