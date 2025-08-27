#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(k+1, 0)),cur(2, vector<int>(k+1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= k; cap++)
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

        return cur[0][k];
    }
};

int main()
{
    vector<int> prices = {3,2,6,5,0,3};
    int k = 2;
    cout << Solution().maxProfit(k,prices) << endl;
    return 0;
}