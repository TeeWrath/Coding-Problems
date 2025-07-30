#include <bits/stdc++.h>
using namespace std;

// recursion
class Solutionr
{
public:
    int countPaths(int i, int j, int m, int n, vector<vector<int>> &triangle)
    {
        if (i >= m || j >= n)
            return INT_MAX;
        if (i == m - 1 && j < n)
            return triangle[i][j];

        int down = 0, right = 0;
        down = countPaths(i + 1, j, m, triangle[i + 1].size(), triangle);
        right = countPaths(i + 1, j + 1, m, triangle[i + 1].size(), triangle);

        return triangle[i][j] + min(down, right);
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        return countPaths(0, 0, triangle.size(), triangle[0].size(), triangle);
    }
};

// tabulation
class Solutiont
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int i = 0; i < m; i++)
        {
            dp[m - 1][i] = triangle[m - 1][i];
        }

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                    int down = dp[i + 1][j];
                    int right = dp[i + 1][j + 1];

                dp[i][j] = triangle[i][j] + min(down, right);
            }
        }

        return dp[0][0];
    }
};

// space optimization
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        vector<int> dp(m, 0);

        for (int i = 0; i < m; i++)
        {
            dp[i] = triangle[m - 1][i];
        }

        for (int i = m - 2; i >= 0; i--)
        {
            vector<int> temp(m,0);
            for (int j = i; j >= 0; j--)
            {
                    int down = dp[j];
                    int right = dp[j + 1];

                temp[j] = triangle[i][j] + min(down, right);
            }
            dp = temp;
        }

        return dp[0];
    }
};

// most space optimized - inplace change
class Solution {
    public:
        int minimumTotal(vector<vector<int>>& tr) 
        {
            int n=tr.size();
            for(int i=n-2;i>=0;i--)
            {
                for(int j=0;j<tr[i].size();j++)
                {
                     tr[i][j]+=min(tr[i+1][j],tr[i+1][j+1]);
                }
            }
            return tr[0][0];
        }
    };

int main()
{
    vector<vector<int>> traingle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout << "Min Path sum: " << Solution().minimumTotal(traingle) << endl;
    return 0;
}