#include <bits/stdc++.h>
using namespace std;

// recursive
class Solutionr
{
public:
    int countMinPath(int i, int j, int m, int n, vector<vector<int>> &grid)
    {
        if (i == m - 1 && j == n - 1)
            return grid[i][j];
        if (i >= m || j >= n)
            return INT_MAX;

        int down = 0, right = 0;
        down = countMinPath(i + 1, j, m, n, grid);
        right = countMinPath(i, j + 1, m, n, grid);

        return grid[i][j] + min(right, down);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        return countMinPath(0, 0, m, n, grid);
    }
};

// memoization
class Solutionm
{
public:
    int countMinPath(int i, int j, int m, int n, vector<vector<int>> &grid,vector<vector<int>>& dp)
    {
        if (i == m - 1 && j == n - 1)
            return grid[i][j];
        if (i >= m || j >= n)
            return INT_MAX;
        if(dp[i][j] != -1)return dp[i][j];

        int down = 0, right = 0;
        down = countMinPath(i + 1, j, m, n, grid,dp);
        right = countMinPath(i, j + 1, m, n, grid,dp);

        return dp[i][j] = grid[i][j] + min(right, down);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return countMinPath(0, 0, m, n, grid,dp);
    }
};

// tabulation
class Solutiont
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[i][j];
                    continue;
                }

                int up=INT_MAX,left=INT_MAX;
                if(i>0)up = dp[i-1][j];
                if(j>0)left = dp[i][j-1];

                dp[i][j] =  grid[i][j] + min(up,left);
            }
        }

        return dp[m-1][n-1];
    }
};

// space optimization
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;
        vector<int> dp(n,0);

        for(int i=0; i<m; i++){
            vector<int> temp(n,0);
            for(int j=0; j<n;j++){
                if(i==0 && j==0){
                    temp[j]=grid[i][j];
                    continue;
                }

                int up=INT_MAX,left=INT_MAX;
                if(i>0)up = dp[j];
                if(j>0)left = temp[j-1];

                temp[j] =  grid[i][j] + min(up,left);
            }
            dp = temp;
        }

        return dp[n-1];
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << "Minimum path sum: " << Solution().minPathSum(grid) << endl;
    return 0;
}