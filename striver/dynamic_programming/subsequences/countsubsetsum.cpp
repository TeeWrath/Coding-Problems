#include <bits/stdc++.h>
using namespace std;

// recursive
int fr(int i, int target, vector<int>& arr){
    if(target == 0)return 1;
    if(i == 0)return arr[i] == target;

    int notTake = fr(i-1,target,arr);
    int take=0;
    if(arr[i] <= target)take = fr(i-1,target - arr[i],arr);

    return take + notTake;
}

int findWays(vector<int>& arr, int k)
{
    int n = arr.size();
    return fr(n-1,k,arr);
}

// memoization
int fm(int i, int target, vector<int>& arr,vector<vector<int>> &dp){
    if(target == 0)return 1;
    if(i == 0)return arr[i] == target ? 1:0;
    if(dp[i][target] != -1)return dp[i][target];

    int notTake = fm(i-1,target,arr,dp);
    int take=0;
    if(arr[i] <= target)take = fm(i-1,target - arr[i],arr,dp);

    return dp[i][target] = take + notTake;
}

int findWays(vector<int>& arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return fm(n-1,k,arr,dp);
}

// tabulation
int findWayst(vector<int>& arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));

    for(int i=0;i<n;i++)dp[i][0]=1;
    if(arr[0] <=k)dp[0][arr[0]]=1;

    for(int i=1;i<n;i++){
        for(int target =1;target <=k;target++){
            int notpick = dp[i-1][target];
            int pick = 0;
            if(arr[i] <= target)pick = dp[i-1][target - arr[i]];
            dp[i][target] = pick + notpick;
        }
    }

    return dp[n-1][k];
}

// space optimized
int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    int mod = 1e9 + 7; // Define the modulo value

    // 'prev' vector stores the results for the previous row (i-1)
    vector<int> prev(k + 1, 0);

    // --- Base Case Initialization for the first element (arr[0]) ---
    
    // The problem constraints state 0 <= arr[i], so we must handle arr[0] = 0.
    if (arr[0] == 0) {
        // If the first element is 0, we have two ways to make sum 0:
        // 1. Don't pick it (empty set)
        // 2. Pick it ({0})
        prev[0] = 2;
    } else {
        // If the first element is not 0, there is one way to make sum 0 (empty set)
        prev[0] = 1;
        // And if arr[0] is within the target sum, there's one way to make sum arr[0]
        if (arr[0] <= k) {
            prev[arr[0]] = 1;
        }
    }

    // --- DP Calculation for the rest of the array ---
    for (int i = 1; i < n; i++) {
        // 'curr' vector to calculate results for the current row (i)
        vector<int> curr(k + 1, 0);
        for (int target = 0; target <= k; target++) {
            // Option 1: Don't pick the current element arr[i]
            int notPick = prev[target];

            // Option 2: Pick the current element arr[i]
            int pick = 0;
            if (arr[i] <= target) {
                pick = prev[target - arr[i]];
            }
            
            // Total ways is the sum of both options, with modulo
            curr[target] = (pick + notPick) % mod;
        }
        // The current row's results become the previous row for the next iteration
        prev = curr;
    }

    // The final answer is the number of ways to form the target sum 'k'
    return prev[k];
}