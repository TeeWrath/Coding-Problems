#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution
{
private:
    int solve(vector<int> &nums, int index, vector<int> &dp)
    {
        if (index == 0)
            return nums[0];
        if (index < 0)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int pick = nums[index] + solve(nums, index - 2, dp);
        int notPick = solve(nums, index - 1, dp);

        return dp[index] = max(pick, notPick);
    }

public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return solve(nums, nums.size() - 1, dp);
    }
};

// tabulation
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += dp[i - 2];
            int nonPick = dp[i - 1];

            dp[i] = max(pick, nonPick);
        }
        return dp[nums.size() - 1];
    }
};

// space optimization
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += prev2;
            int nonPick = prev;

            int cur = max(pick, nonPick);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};