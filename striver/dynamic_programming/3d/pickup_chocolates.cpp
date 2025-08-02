#include <bits/stdc++.h>
using namespace std;

// memoization
int countChocolates(int i, int j1, int j2, int m, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
        return -1e8;
    if (i == m - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int maxi = INT_MIN;

    for (int d1 = -1; d1 <= 1; d1++)
    {
        for (int d2 = -1; d2 <= 1; d2++)
        {
            int ans;

            if (j1 == j2)
                ans = grid[i][j1] + countChocolates(i + 1, j1 + d1, j2 + d2, m, n, grid, dp);
            else
                ans = grid[i][j1] + grid[i][j2] + countChocolates(i + 1, j1 + d1, j2 + d2, m, n, grid, dp);

            maxi = max(maxi, ans);
        }
    }

    return dp[i][j1][j2] = maxi;
}

int maximumChocolatesr(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return countChocolates(0, 0, c - 1, r, c, grid, dp);
}

// tabulation
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // FIX: Handle the edge case of an empty grid.
    if (r == 0)
        return 0;

    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

    // Base case: Initialize the last row of the DP table
    for (int j1 = 0; j1 < c; j1++)
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
                dp[r - 1][j1][j2] = grid[r - 1][j1];
            else
                dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    // Iterate from the second-to-last row up to the top row
    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                // First, find the maximum possible value from the next row (i+1)
                int max_from_next_row = -1e9;
                for (int d1 = -1; d1 <= 1; d1++)
                {
                    for (int d2 = -1; d2 <= 1; d2++)
                    {
                        // Check if the next move is valid
                        if (j1 + d1 >= 0 && j1 + d1 < c && j2 + d2 >= 0 && j2 + d2 < c)
                        {
                            max_from_next_row = max(max_from_next_row, dp[i + 1][j1 + d1][j2 + d2]);
                        }
                    }
                }

                // Now, add the chocolates from the current cells
                int current_chocolates = 0;
                if (j1 == j2)
                    current_chocolates = grid[i][j1];
                else
                    current_chocolates = grid[i][j1] + grid[i][j2];

                dp[i][j1][j2] = current_chocolates + max_from_next_row;
            }
        }
    }

    // The final answer is when Alice starts at (0,0) and Bob starts at (0, c-1)
    return dp[0][0][c - 1];
}

int main()
{
    vector<vector<int>> grid = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    cout << "Max choco: " << maximumChocolates(3, 4, grid) << endl;
    return 0;
}