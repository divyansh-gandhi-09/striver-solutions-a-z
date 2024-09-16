#include <bits/stdc++.h>
using namespace std;

int minJumps(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return 0;
    if (arr[0] == 0) return -1;

    int maxreach = arr[0];
    int steps = arr[0];
    int jumps = 1;

    for (int i = 1; i < n; i++) {
        if (i == n - 1) return jumps;
        
        maxreach = max(maxreach, arr[i] + i);
        steps--;
        
        if (steps == 0) {
            jumps++;
            if (i >= maxreach) return -1;
            steps = maxreach - i;
        }
    }

    return -1; // This return is added to handle the case where the end is not reachable.
}

int main() {
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(2);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(6);
    arr.push_back(8);
    arr.push_back(9);
    int res = minJumps(arr);
    cout << res << endl;
    return 0;
}
