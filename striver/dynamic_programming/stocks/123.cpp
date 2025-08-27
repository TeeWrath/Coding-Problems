#include <bits/stdc++.h>
using namespace std;

class Solutionm
{
public:
    int f(int i, int buy, int cap, int n, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (cap == 0)
            return 0;
        if (i == n)
            return 0;
        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];
        long profit = 0;

        if (buy == 0)
            profit = max(-prices[i] + f(i + 1, !buy, cap, n, prices, dp), f(i + 1, buy, cap, n, prices, dp));
        else
            profit = max(prices[i] + f(i + 1, !buy, cap - 1, n, prices, dp), f(i + 1, buy, cap, n, prices, dp));

        return dp[i][buy][cap] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 0, 2, n, prices, dp);
    }
};

class Solutiont
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    long profit = 0;

                    if (buy == 0)
                        profit = max(-prices[i] + dp[i + 1][!buy][cap], dp[i + 1][buy][cap]);
                    else
                        profit = max(prices[i] + dp[i + 1][!buy][cap - 1], dp[i + 1][buy][cap]);

                    dp[i][buy][cap] = profit;
                }
            }
        }

        return dp[0][0][2];
    }
};

// space optimized
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(3, 0)),cur(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    long profit = 0;

                    if (buy == 0)
                        profit = max(-prices[i] + after[!buy][cap], after[buy][cap]);
                    else
                        profit = max(prices[i] + after[!buy][cap - 1], after[buy][cap]);

                    cur[buy][cap] = profit;
                }
            }
            after = cur;
        }

        return cur[0][2];
    }
};

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}