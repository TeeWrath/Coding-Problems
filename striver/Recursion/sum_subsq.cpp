#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printSubsequences(vector<int> &arr, int idx, vector<int> &res, int sum, int s) {
    if (idx == arr.size()) {
        if(s == sum){
            printArray(res);
        }
        return;
    }
    
    // Include the current element
    res.push_back(arr[idx]);
    s += arr[idx];
    printSubsequences(arr, idx + 1, res, sum,s);
    
    // Exclude the current element (remove the last added element)
    s -= arr[idx];
    res.pop_back();
    printSubsequences(arr, idx + 1, res,sum,s);
}

int main() {
    vector<int> arr = {1, 2, 1};
    vector<int> res;
    printSubsequences(arr, 0, res,3,0);
    return 0;
}