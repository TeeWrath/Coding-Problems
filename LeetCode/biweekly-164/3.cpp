#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int mod = 1e9 + 7;
    
    // Helper function to handle reflections recursively
    pair<int, int> reflect(int i, int j, int dir, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Keep reflecting until we hit an empty cell or go out of bounds
        while (i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == 1) {
            if (dir == 0) { // Moving right -> reflect to down
                i++;
                dir = 1;
            } else { // Moving down -> reflect to right
                j++;
                dir = 0;
            }
        }
        
        return {i, j};
    }
    
    int solve(int i, int j, int dir, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Check if out of bounds after reflections
        if (i < 0 || j < 0 || i >= n || j >= m) return 0;
        
        // Check if reached destination
        if (i == n - 1 && j == m - 1) return 1;
        
        // Memoization check
        if (dp[i][j][dir] != -1) return dp[i][j][dir];
        
        int count = 0;
        
        if (grid[i][j] == 1) {
            // Handle mirror reflection
            auto [new_i, new_j] = reflect(i, j, dir, grid);
            count = solve(new_i, new_j, dir, grid, dp) % mod;
        } else {
            // Empty cell - continue in current direction
            if (dir == 0) { // Moving right
                count = solve(i, j + 1, 0, grid, dp) % mod;
            } else { // Moving down
                count = solve(i + 1, j, 1, grid, dp) % mod;
            }
        }
        
        return dp[i][j][dir] = count;
    }
    
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // dp[i][j][dir] where dir: 0 = right, 1 = down
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));
        
        // Start moving right from (0,0)
        return solve(0, 0, 0, grid, dp);
    }
};

int main() {
    vector<vector<int>> grid = {{0,1,0},{0,0,1},{1,0,0}};
    Solution sol;
    cout << sol.uniquePaths(grid) << endl; // Should output 5
    return 0;
}