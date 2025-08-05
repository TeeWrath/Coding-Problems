#include <bits/stdc++.h>
using namespace std;

// recursion
class Solutionr
{
public:
    bool f(int i, int n, int target, vector<int> &nums)
    {
        if (target == 0)
            return true;
        if (i == 0)
            return nums[i] == target;

        bool notPick = f(i - 1, n, target, nums);
        bool pick = false;
        if (target >= nums[i])
            pick = f(i - 1, n, target - nums[i], nums);

        return pick || notPick;
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int totSum = 0;
        for (int i = 0; i < n; i++)
        {
            totSum += nums[i];
        }

        if (totSum % 2 == 1)
            return false;
        int k = totSum / 2;

        return f(n - 1, n, k, nums);
    }
};

// space optimized
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int totSum = 0;
        for (int i = 0; i < n; i++)
        {
            totSum += nums[i];
        }

        if (totSum % 2 == 1)
            return false;
        int k = totSum / 2;

        vector<bool> prev(k + 1, false), cur(k + 1, false);
        prev[0] = cur[0] = true;

        if (nums[0] <= k)
            prev[nums[0]] = true;

        for (int i = 1; i < n; i++)
        {
            for (int target = 1; target <= k; target++)
            {
                bool notPick = prev[target];
                bool pick = false;
                if (target >= nums[i])
                    pick = prev[target - nums[i]];
                cur[target] = pick || notPick;
            }
            prev = cur;
        }

        return prev[k];
    }
};

// most optimal
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int target = 0;
        for (int num : nums)
        {
            target += num;
        }
        if (target % 2 == 1)
        {
            return false;
        }
        bitset<10001> bit(1);
        for (int num : nums)
        {
            bit |= bit << num;
        }
        return bit[target / 2];
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 5};
    cout << Solution().canPartition(nums) << endl;
    return 0;
}