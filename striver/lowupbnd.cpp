#include<bits/stdc++.h>
using namespace std;

// Program to find both ceil and floor together in single function using BINARY SEARCH
class Solution {
public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(2, -1);
        
        // Sorting is required as binary search works on sorted data
        sort(arr.begin(), arr.end());

        // Finding Floor (largest element ≤ x)
        int l = 0, h = n - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (arr[m] <= x) {
                ans[0] = arr[m]; // Potential floor value
                l = m + 1; // Move right to find a larger valid floor
            } else {
                h = m - 1;
            }
        }

        // Finding Ceil (smallest element ≥ x)
        l = 0, h = n - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (arr[m] >= x) {
                ans[1] = arr[m]; // Potential ceil value
                h = m - 1; // Move left to find a smaller valid ceil
            } else {
                l = m + 1;
            }
        }

        return ans;
    }
};