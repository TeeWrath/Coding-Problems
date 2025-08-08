#include <bits/stdc++.h>
using namespace std;

// recursive
class Solutionr
{
    int f(int i, int n, int target, vector<int> &nums)
    {
        if (i < 0)
            return target == 0 ? 1 : 0;

        int pos = f(i - 1, n, target - nums[i], nums);
        int neg = f(i - 1, n, target + nums[i], nums);

        return pos + neg;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        return f(n - 1, n, target, nums);
    }
};

// memoization

class Solutionm {
    int f(int i, int k, vector<int> &arr, vector<vector<int>> &dp) {
        if (i < 0) {
            return k == 0 ? 1 : 0;
        }
        if (k < 0) {
            return 0;
        }
        if (dp[i][k] != -1) {
            return dp[i][k];
        }

        if (arr[i] == 0) {
            // For zero, we can either take it or not take it, both are valid
            return dp[i][k] = 2 * f(i - 1, k, arr, dp);
        }

        int notPick = f(i - 1, k, arr, dp);
        int pick = f(i - 1, k - arr[i], arr, dp);

        return dp[i][k] = pick + notPick;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int n = nums.size();
        int totsum = accumulate(nums.begin(), nums.end(), 0);

        if (totsum < abs(target) || (totsum + target) % 2 != 0) {
            return 0;
        }

        int newTarget = (totsum + target) / 2;

        vector<vector<int>> dp(n, vector<int>(newTarget + 1, -1));
        return f(n - 1, newTarget, nums, dp);
    }
};

// tabulation
class Solutiont {
    public:
        int findTargetSumWays(vector<int> &nums, int target) {
            int n = nums.size();
            int totsum = accumulate(nums.begin(), nums.end(), 0);
    
            if (totsum < abs(target) || (totsum + target) % 2 != 0) {
                return 0;
            }
    
            int newTarget = (totsum + target) / 2;
    
            vector<vector<int>> dp(n, vector<int>(newTarget + 1, 0));
    
            // Initialize dp[0][0]
            dp[0][0] = 1;
            if (nums[0] == 0) {
                dp[0][0] = 2;  // Can choose to include or exclude the zero
            } else if (nums[0] <= newTarget) {
                dp[0][nums[0]] = 1;
            }
    
            for (int i = 1; i < n; i++) {
                for (int k = 0; k <= newTarget; k++) {
                    int notpick = dp[i-1][k];
                    int pick = (k >= nums[i]) ? dp[i-1][k - nums[i]] : 0;
                    dp[i][k] = pick + notpick;
                    if (nums[i] == 0) {
                        // For zero, both pick and notpick are valid, so we double the count
                        dp[i][k] = 2 * dp[i-1][k];
                    }
                }
            }
    
            return dp[n-1][newTarget];
        }
    };

// space optimization
class Solution {
    public:
        int findTargetSumWays(vector<int> &nums, int target) {
            int n = nums.size();
            int totsum = accumulate(nums.begin(), nums.end(), 0);
    
            if (totsum < abs(target) || (totsum + target) % 2 != 0) {
                return 0;
            }
    
            int newTarget = (totsum + target) / 2;
    
            vector<int> prev(newTarget + 1, 0);
    
            // Initialize dp[0][0]
            prev[0] = 1;
            if (nums[0] == 0) {
                prev[0] = 2;  // Can choose to include or exclude the zero
            } else if (nums[0] <= newTarget) {
                prev[nums[0]] = 1;
            }
    
            for (int i = 1; i < n; i++) {
                vector<int> cur(newTarget+1,0);
                for (int k = 0; k <= newTarget; k++) {
                    int notpick = prev[k];
                    int pick = (k >= nums[i]) ? prev[k - nums[i]] : 0;
                    cur[k] = pick + notpick;
                    if (nums[i] == 0) {
                        // For zero, both pick and notpick are valid, so we double the count
                        cur[k] = 2 * prev[k];
                    }
                }
                prev = cur;
            }
    
            return prev[newTarget];
        }
    };

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << Solution().findTargetSumWays(nums, 3) << endl;
    return 0;
}