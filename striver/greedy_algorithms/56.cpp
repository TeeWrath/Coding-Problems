#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> res;

    for(int i=0; i< n ;i++){
        if(res.empty() || intervals[i][0] > res.back()[1]) res.push_back(intervals[i]);
        else res.back()[1] = max(res.back()[1], intervals[i][1]);
    }
    return res;
}

int main(){
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    // vector<vector<int>> intervals = {{1,4},{4,5}};
    vector<vector<int>> ans = merge(intervals);
    
    // Print the result
    for (int i = 0; i < ans.size(); i++) {
        cout << "[" << ans[i][0] << "," << ans[i][1] << "] ";
    }
    cout << endl;
    return 0;
}