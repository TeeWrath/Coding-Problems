#include <bits/stdc++.h>
using namespace std;

class Solutionm
{
public:
    bool f(int i, int j, string s, string p, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
            return true;
        if (j < 0)
            return false;
        if (i < 0)
        {
            for (int k = 0; k <= j; k++)
                if (p[k] != '*')
                    return false;
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);
        else if (p[j] == '*')
            return dp[i][j] = f(i, j - 1, s, p, dp) || f(i - 1, j, s, p, dp);
        return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, p, dp);
    }
};

// tabulation
class Solutiont
{
public:
    bool isAllStars(string &s, int j) // Check first j characters
    {
        for (int i = 0; i < j; i++) // Check from index 0 to j-1
        {
            if (s[i] != '*')
                return false;
        }
        return true;
    }

public:
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        dp[0][0] = true;
        for (int j = 1; j <= m; j++)
            dp[0][j] = isAllStars(p, j);
        for (int i = 1; i <= n; i++)
            dp[i][0] = false;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else
                    dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
};

// space optimized
class Solution
{
public:
    bool isAllStars(string &s, int j) // Check first j characters
    {
        for (int i = 0; i < j; i++) // Check from index 0 to j-1
        {
            if (s[i] != '*')
                return false;
        }
        return true;
    }

public:
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<int> prev(m + 1, 0),cur(m+1,0);

        prev[0] = true;
        for (int j = 1; j <= m; j++)
            prev[j] = isAllStars(p, j);

        for (int i = 1; i <= n; i++)
        {
            cur[0]=false;
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    cur[j] = prev[j - 1];
                else if (p[j - 1] == '*')
                    cur[j] = cur[j - 1] || prev[j];
                else
                    cur[j] = false;
            }
            prev =cur;
        }

        return prev[m];
    }
};


int main()
{
    string s, p;
    cin >> s >> p;
    cout << Solution().isMatch(s, p) << endl;
    return 0;
}