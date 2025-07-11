#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> difference(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        difference[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<int> dRow = {1, -1, 0, 0};
        vector<int> dCol = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if (row == n - 1 && col == m - 1) {
                return diff;
            }

            for (int i = 0; i < 4; i++) {
                int nRow = row + dRow[i];
                int nCol = col + dCol[i];

                if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m) {
                    int newDiff = max(diff, abs(heights[row][col] - heights[nRow][nCol]));
                    if (newDiff < difference[nRow][nCol]) {
                        difference[nRow][nCol] = newDiff;
                        pq.push({newDiff, {nRow, nCol}});
                    }
                }
            }
        }

        return difference[n - 1][m - 1];
    }
};