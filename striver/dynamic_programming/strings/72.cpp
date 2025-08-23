#include <bits/stdc++.h>
using namespace std;

// recursion
class Solutionr
{
public:
    int f(int i, int j, string s, string t)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;

        if (s[i] == t[j])
            return f(i - 1, j - 1, s, t);

        // insert
        int ins = 1 + f(i, j - 1, s, t);

        // delete
        int del = 1 + f(i - 1, j, s, t);

        // replace
        int rep = 1 + f(i - 1, j - 1, s, t);

        return min(ins, min(del, rep));
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        return f(n - 1, m - 1, word1, word2);
    }
};

// memoization
class Solutionm
{
public:
    int f(int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = f(i - 1, j - 1, s, t, dp);

        // insert
        int ins = 1 + f(i, j - 1, s, t, dp);

        // delete
        int del = 1 + f(i - 1, j, s, t, dp);

        // replace
        int rep = 1 + f(i - 1, j - 1, s, t, dp);

        return dp[i][j] = min(ins, min(del, rep));
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, word1, word2, dp);
    }
};

// tabulation
class Solutiont
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];

                else{
                    // insert
                int ins = 1 + dp[i][j - 1];

                // delete
                int del = 1 + dp[i - 1][j];

                // replace
                int rep = 1 + dp[i - 1][j - 1];

                dp[i][j] = min(ins, min(del, rep));
                }
            }
        }
        return dp[n][m];
    }
};

// space complexity
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m + 1, 0),cur(m+1,0);

        for(int j=0;j<=m;j++)prev[j]=j;

        for (int i = 1; i <= n; i++)
        {
            cur[0] = i;
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    cur[j] = prev[j - 1];

                else{
                    // insert
                int ins = 1 + cur[j - 1];

                // delete
                int del = 1 + prev[j];

                // replace
                int rep = 1 + prev[j - 1];

                cur[j] = min(ins, min(del, rep));
                }
            }
            prev = cur;
        }
        return prev[m];
    }
};

int main()
{
    string s, t;
    cin >> s >> t;
    cout << Solution().minDistance(s, t) << endl;
    return 0;
}