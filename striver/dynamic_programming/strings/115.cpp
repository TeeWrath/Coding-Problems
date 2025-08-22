#include <bits/stdc++.h>
using namespace std;

// recursive
class Solutionr
{
public:
    int f(int i, int j, string s, string t)
    {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (s[i] == t[j])
        {
            return f(i - 1, j - 1, s, t) + f(i - 1, j, s, t);
        }
        else
            return f(i - 1, j, s, t);
    }

public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        return f(n - 1, m - 1, s, t);
    }
};

// memoization
class Solutionm
{
public:
    int f(int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        if (j == 0)
            return 1;
        if (i == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i - 1] == t[j - 1])
        {
            return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
        }
        else
            return dp[i][j] = f(i - 1, j, s, t, dp);
    }

public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n, m, s, t, dp);
    }
};

// tabulation
class Solutiont
{
public: using ll = unsigned long long;
public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int j = 1; j <= m; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][ j - 1] + dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1] [j];
            }
        }
        return dp[n][m];
    }
};

// space optimized
class Solution
{
public: using ll = unsigned long long;
public:
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<ll> prev(m + 1, 0);
            prev[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                if (s[i - 1] == t[j - 1])prev[j] = prev[ j - 1] + prev[j];
            }
        }
        return prev[m];
    }
};

int main()
{
    string s, t;
    cin >> s >> t;
    cout << Solution().numDistinct(s, t) << endl;
    return 0;
}