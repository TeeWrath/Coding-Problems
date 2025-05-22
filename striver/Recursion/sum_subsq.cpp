#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int printSubsequences(vector<int> &arr, int idx, vector<int> &res, int sum, int s) {
    if (idx == arr.size()) {
        if(s == sum){
            // printArray(res);
            return 1;
        }
        else return 0;
    }
    
    // Include the current element
    res.push_back(arr[idx]);
    s += arr[idx];
    // if(printSubsequences(arr, idx + 1, res, sum,s)) return true;
    int left = printSubsequences(arr,idx +1,res,sum,s);
    
    // Exclude the current element (remove the last added element)
    s -= arr[idx];
    res.pop_back();
    // if(printSubsequences(arr, idx + 1, res,sum,s)) return true;
    int right = printSubsequences(arr,idx +1,res,sum,s);

    return left + right;
}

int main() {
    vector<int> arr = {1, 2, 1,5,2,4,5,9,7,3,6,5,11};
    // vector<int> arr = {1,2,1};
    vector<int> res;
    cout << printSubsequences(arr, 0, res,25,0);
    return 0;
}