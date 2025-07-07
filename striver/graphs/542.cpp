#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int n = mat.size();
            if (n == 0) return mat;
            int m = mat[0].size();
            
            vector<vector<int>> distance(n, vector<int>(m, 0));
            vector<vector<int>> vis(n, vector<int>(m, 0));
            queue<pair<int, int>> q; // Store {row, col}
            
            // Initialize queue with all 0s and mark them as visited
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (mat[i][j] == 0) {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
            
            // Directions: down, up, right, left
            int dRow[] = {1, -1, 0, 0};
            int dCol[] = {0, 0, 1, -1};
            
            // BFS
            int steps = 0;
            while (!q.empty()) {
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    
                    // Set distance for the current cell
                    distance[row][col] = steps;
                    
                    // Explore neighbors
                    for (int d = 0; d < 4; d++) {
                        int nRow = row + dRow[d];
                        int nCol = col + dCol[d];
                        
                        // Check if neighbor is valid and unvisited
                        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol]) {
                            q.push({nRow, nCol});
                            vis[nRow][nCol] = 1; // Mark as visited
                        }
                    }
                }
                steps++; // Increment distance for the next level
            }
            
            return distance;
        }
    };