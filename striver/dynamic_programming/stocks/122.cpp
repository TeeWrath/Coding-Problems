#include <bits/stdc++.h>
using namespace std;

class Solutionm
{
public:
    int f(int i, int n, bool buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (i == n)
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];

        long profit = 0;
        if (buy)
            profit = max(0 + f(i + 1, n, buy, prices, dp), -prices[i] + f(i + 1, n, !buy, prices, dp));
        else
            profit = max(0 + f(i + 1, n, buy, prices, dp), prices[i] + f(i + 1, n, !buy, prices, dp));

        return dp[i][buy] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return n;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, n, 1, prices, dp);
    }
};

class Solutiont
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return n;
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        dp[n][0] = dp[n][1] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                long profit = 0;
                if (buy == 0)
                    profit = max(0 + dp[i + 1][buy], -prices[i] + dp[i + 1][!buy]);
                else
                    profit = max(0 + dp[i + 1][buy], prices[i] + dp[i + 1][!buy]);
                
                    dp[i][buy] = profit;
            }
        }
        return dp[0][0];
    }
};

// space optimization
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return n;
        vector<int> prev(2, 0),cur(2,0);
        prev[0] = prev[1] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                long profit = 0;
                if (buy == 0)
                    profit = max(0 + prev[buy], -prices[i] + prev[!buy]);
                else
                    profit = max(0 + prev[buy], prices[i] + prev[!buy]);
                
                    cur[buy] = profit;
            }
            prev = cur;
        }
        return cur[0];
    }
};

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}