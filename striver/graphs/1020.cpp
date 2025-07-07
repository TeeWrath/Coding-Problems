#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void dfs(int row, int column, vector<vector<int>> &vis, vector<vector<int>> &grid)
    {
        vis[row][column] = 1;
        int n = grid.size();
        int m = grid[0].size();

        int delRow[] = {1, -1, 0, 0};
        int delCol[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++)
        {
            int nRow = row + delRow[i];
            int nCol = column + delCol[i];
            if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 1)
                dfs(nRow, nCol, vis, grid);
        }
    }
    public:
        int numEnclaves(vector<vector<int>>& grid) {
            int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++)
        {
            if (!vis[0][j] && grid[0][j] == 1)
                dfs(0, j, vis, grid);
            if (!vis[n - 1][j] && grid[n - 1][j] == 1)
                dfs(n - 1, j, vis, grid);
        }

        for (int i = 0; i < n; i++)
        {
            if (!vis[i][0] && grid[i][0] == 1)
                dfs(i, 0, vis, grid);
            if (!vis[i][m - 1] && grid[i][m - 1] == 1)
                dfs(i, m - 1, vis, grid);
        }

        int cnt=0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
        }
    };