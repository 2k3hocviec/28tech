#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int costNoiDay(priority_queue<int, vector<int>, greater<int>>& minHeap) {
    int cost = 0;
    if (minHeap.size() == 0) return cost;
    while (minHeap.size() != 1) {
        int i = minHeap.top(); minHeap.pop();
        int j = minHeap.top(); minHeap.pop();
        minHeap.push(i + j);
        cost += i + j;
    }
    return cost;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int n; 
    cin >> n;
    while (n--) {
        int i; cin >> i;
        minHeap.push(i);
    }
    cout << costNoiDay(minHeap);
    return 0;
}

