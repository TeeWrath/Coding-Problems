#include <bits/stdc++.h>
using namespace std;

class Solutionm
{
public:
    int f(int i, int buy, int fee, int n, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (i == n)
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];

        long prof = 0;
        if (buy == 0)
            prof += max(-prices[i] + f(i + 1, !buy, fee, n, prices, dp), f(i + 1, buy, fee, n, prices, dp));
        else
            prof += max(prices[i] - fee + f(i + 1, !buy, fee, n, prices, dp), f(i + 1, buy, fee, n, prices, dp));

        return dp[i][buy] = prof;
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 0, fee, n, prices, dp);
    }
};

class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        if (n == 0)
            return 0;
        vector<int> after(2, 0), cur(2, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {

                long prof = 0;
                if (buy == 0)
                    prof += max(-prices[i] + after[!buy], after[buy]);
                else
                    prof += max(prices[i] - fee + after[!buy], after[buy]);
                
                cur[buy] = prof;
            }
            after = cur;
        }

        return cur[0];
    }
};

int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << Solution().maxProfit(prices, fee) << endl;
    return 0;
}