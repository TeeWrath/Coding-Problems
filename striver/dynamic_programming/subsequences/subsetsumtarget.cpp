#include <bits/stdc++.h>
using namespace std;

// recursion
bool f(int i, int n, int k, vector<int> &arr)
{
    if (k == 0)
        return true;
    if (i == 0)
        return arr[i] == k;

    bool notPick = f(i - 1, n, k, arr);
    bool pick = false;
    if (k >= arr[i])
        pick = f(i - 1, n, k - arr[i], arr);

    return pick || notPick;
}

bool subsetSumToKr(int n, int k, vector<int> &arr)
{
    return f(n - 1, n, k, arr);
}

// memoization
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

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, n, k, arr, dp);
}

// tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)dp[i][0] = true;
    
    if (arr[0] <= k)dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= k; target++) {
            bool notPick = dp[i - 1][target];
            bool pick = false;
            if (target >= arr[i])pick = dp[i - 1][target - arr[i]];
            dp[i][target] = pick || notPick;
        }
    }

    return dp[n-1][k];
}

// space optimization
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1,false),cur(k+1,false);
    prev[0] = cur[0] = true;
    
    if (arr[0] <= k)prev[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= k; target++) {
            bool notPick = prev[target];
            bool pick = false;
            if (target >= arr[i])pick = prev[target - arr[i]];
            cur[target] = pick || notPick;
        }
        prev = cur;
    }

    return prev[k];
}