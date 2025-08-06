#include <bits/stdc++.h>
using namespace std;

// recursion
class Solutionr
{
public:
    int f(int i, int count, int n, int total, int sum, vector<int> &nums)
    {
        if (count == n)
            return abs(2 * sum - total);
        if (i == nums.size())
            return INT_MAX;

        int pick = f(i + 1, count + 1, n, total, sum + nums[i], nums);
        int notPick = f(i + 1, count, n, total, sum, nums);

        return min(pick, notPick);
    }

public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        return f(0, 0, n / 2, total, 0, nums);
    }
};

// memoization
class Solutionm
{
public:
    bool f(int i, int n, int k, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (k == 0)
            return true;
        if (i == 0)
            return arr[i] == k;
        if (dp[i][k] != -1)
            return dp[i][k];

        bool notPick = f(i - 1, n, k, arr, dp);
        bool pick = false;
        if (k >= arr[i])
            pick = f(i - 1, n, k - arr[i], arr, dp);

        return dp[i][k] = pick || notPick;
    }

public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> dp(n, vector<int>(total + 1, -1));

        for (int i = 0; i <= total; i++)
        {
            bool dum = f(n - 1, n, i, nums, dp);
        }

        int mini = 1e9;
        for (int i = 0; i <= total; i++)
        {
            if (dp[n - 1][i] == true)
            {
                int diff = abs(i - (total - i));
                mini = min(mini, diff);
            }
        }

        return mini;
    }
};

// tabulation
class Solution
{

public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<bool>> dp(n, vector<bool>(total + 1, false));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (nums[0] <= total)
            dp[0][total] = true;

        for (int i = 1; i < n; i++)
        {
            for (int target = 1; target <= total; target++)
            {
                bool notPick = dp[i - 1][target];
                bool pick = false;
                if (target >= nums[i])
                    pick = dp[i - 1][target - nums[i]];
                dp[i][target] = pick || notPick;
            }
        }

        int mini = 1e9;
        for (int i = 0; i <= total; i++)
        {
            if (dp[n - 1][i] == true)
            {
                int diff = abs(i - (total - i));
                mini = min(mini, diff);
            }
        }

        return mini;
    }
};

int main()
{
    vector<int> nums = {2, -1, 0, 4, -2, -9};
    cout << Solution().minimumDifference(nums) << endl;
    return 0;
}