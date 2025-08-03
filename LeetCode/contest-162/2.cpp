#include <bits/stdc++.h>
using namespace std;

// recursive
class Solutionr
{
public:
    int countEle(int i, int j, vector<int> &nums, int k, int cnt)
    {
        // base case
        if (nums[j] <= nums[i] * k)
            return cnt;
        int removeMin = countEle(i + 1, j, nums, k, cnt + 1);
        int removeMax = countEle(i, j - 1, nums, k, cnt + 1);

        return min(removeMin, removeMax);
    }

public:
    int minRemoval(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        return countEle(0, nums.size() - 1, nums, k, 0);
    }
};

// memoization
class Solutionm
{
public:
    int countEle(int i, int j, vector<int> &nums, int k, vector<vector<int>> &dp)
    {
        // base case
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (1LL * nums[j] <= 1LL * nums[i] * k)
            return dp[i][j] = 0;
        int removeMin = 1 + countEle(i + 1, j, nums, k, dp);
        int removeMax = 1 + countEle(i, j - 1, nums, k, dp);

        return dp[i][j] = min(removeMin, removeMax);
    }

public:
    int minRemoval(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return countEle(0, n - 1, nums, k, dp);
    }
};

class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {

        sort(nums.begin(), nums.end());
        int n = nums.size();

        int i = 0;
        int max_len = 0;
        for (int j = 0; j < n; ++j)
        {
            while (1LL * nums[j] > 1LL * nums[i] * k)
            {
                i++;
            }

            max_len = max(max_len, j - i + 1);
        }
        return n - max_len;
    }
};

int main()
{
    vector<int> nums = {1, 6, 2, 9};
    int k = 3;
    cout << Solution().minRemoval(nums, k) << endl;
    return 0;
}