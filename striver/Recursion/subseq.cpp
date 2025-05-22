#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printSubsequences(vector<int> &arr, int idx, vector<int> &res) {
    if (idx >= arr.size()) {
        printArray(res);
        return;
    }
    
    // Include the current element
    res.push_back(arr[idx]);
    printSubsequences(arr, idx + 1, res);
    
    // Exclude the current element (remove the last added element)
    res.pop_back();
    printSubsequences(arr, idx + 1, res);
}

int main() {
    vector<int> arr = {3, 1, 2};
    vector<int> res;
    printSubsequences(arr, 0, res);
    return 0;
}