#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        int prev = 1, prev2 = 1;
        for (int i = 2; i <= n; i++)
        {
            int cur = prev + prev2;
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};

// most space optimized
class Solutionfastest
{
public:
    int climbStairs(int n)
    {

        if (n == 0)
            return 1;
        if (n == 1)
            return 1;

        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};