#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    int i = 0;
    int n = intervals.size();

    // Add all intervals that come before newInterval (no overlap)
    while (i < n && intervals[i][1] < newInterval[0]) {
        ans.push_back(intervals[i]);
        i++;
    }

    // Merge overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval); // Add the merged (or non-overlapping) newInterval

    // Add remaining intervals
    while (i < n) {
        ans.push_back(intervals[i]);
        i++;
    }

    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}};
    vector<int> newInterval = {4,8};
    vector<vector<int>> ans = insert(intervals, newInterval);
    
    // Print the result
    for (int i = 0; i < ans.size(); i++) {
        cout << "[" << ans[i][0] << "," << ans[i][1] << "] ";
    }
    cout << endl;
    return 0;
}