#include <bits/stdc++.h>
using namespace std;

// recursive
class Solutionr
{
public:
    int countPaths(int i, int j, int m, int n, vector<vector<int>> &grid)
    {
        if (i == m - 1 && j == n - 1 && grid[i][j] != 1)
            return 1;
        if (i == m - 1 && j == n - 1 && grid[i][j] == 1)
            return 0;
        if (i >= m || j >= n)
            return 0;
        if (grid[i][j] == 1)
            return 0;

        int up = 0, right = 0;
        if (i < m)
            up = countPaths(i + 1, j, m, n, grid);
        if (j < n)
            right = countPaths(i, j + 1, m, n, grid);

        return up + right;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        if (n == 0)
            return 0;

        // Check if the starting cell itself is an obstacle
        if (obstacleGrid[0][0] == 1)
        {
            return 0;
        }

        return countPaths(0, 0, m, n, obstacleGrid);
    }
};

// memoization
class Solutionm
{
public:
    int countPaths(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<int>>& dp)
    {
        if (i == m - 1 && j == n - 1 && grid[i][j] != 1)
            return 1;
        if (i == m - 1 && j == n - 1 && grid[i][j] == 1)
            return 0;
        if (i >= m || j >= n)
            return 0;
        if (grid[i][j] == 1)
            return 0;

        if(dp[i][j] != -1)return dp[i][j];

        int up = 0, right = 0;
        if (i < m)
            up = countPaths(i + 1, j, m, n, grid,dp);
        if (j < n)
            right = countPaths(i, j + 1, m, n, grid,dp);

        return dp[i][j] = up + right;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        if (n == 0)
            return 0;

        // Check if the starting cell itself is an obstacle
        if (obstacleGrid[0][0] == 1)
        {
            return 0;
        }

        vector<vector<int>> dp(m,vector<int>(n,-1));

        return countPaths(0, 0, m, n, obstacleGrid,dp);
    }
};

// tabulation
class Solutiont
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        if (n == 0)
            return 0;

        // Check if the starting cell itself is an obstacle
        if (obstacleGrid[0][0] == 1)return 0;

        // Check if destination point is obstacle
        if(obstacleGrid[m-1][n-1] == 1)return 0;

        vector<vector<int>> dp(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[0][0]=1;
                    continue;
                }

                if(obstacleGrid[i][j] == 1){
                    dp[i][j]=0;
                    continue;
                }

                int up=0,left=0;
                if(i>0)up = dp[i-1][j];
                if(j>0)left = dp[i][j-1];

                dp[i][j] = up+left;
            }
        }

        return dp[m-1][n-1];
    }
};

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        if (n == 0)
            return 0;

        // Check if the starting cell itself is an obstacle
        if (obstacleGrid[0][0] == 1)return 0;

        // Check if destination point is obstacle
        if(obstacleGrid[m-1][n-1] == 1)return 0;

        vector<int> dp(n,0);

        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[j] = 1;
                    continue;
                }

                if(obstacleGrid[i][j] == 1){
                    temp[j]=0;
                    continue;
                }

                int up=0,left=0;
                if(i>0)up = dp[j];
                if(j>0)left = temp[j-1];

                temp[j] = up+left;
            }
            dp = temp;
        }

        return dp[n-1];
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << "No. of paths: " << Solution().uniquePathsWithObstacles(grid) << endl;
    return 0;
}