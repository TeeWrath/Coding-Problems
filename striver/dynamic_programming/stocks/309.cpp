#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int i, int buy, int canTrade, int n, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (i == n)
            return 0;
        if (dp[i][buy][canTrade] != -1)
            return dp[i][buy][canTrade];

        long prof = 0;
        if (buy == 0 && canTrade == 0)
            prof += max(-prices[i] + f(i + 1, !buy, canTrade, n, prices, dp), f(i + 1, buy, canTrade, n, prices, dp));
        else if (canTrade == 1)
            prof += f(i + 1, buy, !canTrade, n, prices, dp);
        else
            prof += max(prices[i] + f(i + 1, !buy, !canTrade, n, prices, dp), f(i + 1, buy, canTrade, n, prices, dp));

        return dp[i][buy][canTrade] = prof;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return f(0, 0, 0, n, prices, dp);
    }
};

int main()
{
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}