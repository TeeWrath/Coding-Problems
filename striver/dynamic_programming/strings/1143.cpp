#include <bits/stdc++.h>
using namespace std;

// Recursive
class Solutionr
{
public:
    int f(string &s1, string &s2, int ind1, int ind2)
    {
        if (ind1 < 0 || ind2 < 0)
            return 0;

        if (s1[ind1] == s2[ind2])
            return 1 + f(s1, s2, ind1 - 1, ind2 - 1);
        else
            return max(f(s1, s2, ind1 - 1, ind2), f(s1, s2, ind1, ind2 - 1));
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();
        return f(text1, text2, n1 - 1, n2 - 1);
    }
};

// memoization
class Solutionm
{
public:
    int f(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp)
    {
        if (ind1 < 0 || ind2 < 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (s1[ind1] == s2[ind2])
            return dp[ind1][ind2] = 1 + f(s1, s2, ind1 - 1, ind2 - 1, dp);
        else
            return dp[ind1][ind2] = max(f(s1, s2, ind1 - 1, ind2, dp), f(s1, s2, ind1, ind2 - 1, dp));
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return f(text1, text2, n1 - 1, n2 - 1, dp);
    }
};

// tabulation
class Solutiont
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        for (int i = 0; i <= n1; i++)
            dp[i][0] = 0;
        for (int i = 0; i <= n2; i++)
            dp[0][i] = 0;

        for (int ind1 = 1; ind1 <= n1; ind1++)
        {
            for (int ind2 = 1; ind2 <= n2; ind2++)
            {
                if (text1[ind1 - 1] == text2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                else
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }

        return dp[n1][n2];
    }
};

// space optimized
class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            int n1 = text1.size();
            int n2 = text2.size();
            vector<int> prev(n2+1,0);
            vector<int> cur(n2+1,0);

            for(int ind1=1;ind1<=n1;ind1++){
                for(int ind2=1;ind2<=n2;ind2++){
                    if(text1[ind1-1]== text2[ind2-1])cur[ind2] = 1 + prev[ind2-1];
                    else cur[ind2] = max(prev[ind2],cur[ind2-1]);
                }
                prev = cur;
            }

            return prev[n2];
        }
    };

int main()
{
    string text1, text2;
    cin >> text1 >> text2;

    cout << Solution().longestCommonSubsequence(text1, text2) << endl;
    return 0;
}