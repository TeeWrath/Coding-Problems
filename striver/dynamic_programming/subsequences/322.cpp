#include <bits/stdc++.h>
using namespace std;

// memoization
class Solutionm
{
public:
    int f(int i, int n, int k, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (i == 0){

            if(k%arr[i] == 0)return k/arr[i];
            else return 1e9;
        }
        if (dp[i][k] != -1)
            return dp[i][k];

        int notPick = f(i - 1, n, k, arr, dp);
        int pick = 1e9;
        if (k >= arr[i])
            pick = 1+ f(i, n, k - arr[i], arr, dp);

        return dp[i][k] = min(pick,notPick);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = f(n-1,n,amount,coins,dp);

        if(ans >= 1e9)return -1;
        return ans;
    }
};

// tabulation
class Solutiont
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));

        for(int i=0;i<=amount;i++){
            if (i % coins[0] == 0)
            dp[0][i] = i / coins[0];
        else
            dp[0][i] = 1e9;
        }
        
        for(int i=1;i<n;i++){
            for(int target = 0; target <= amount;target++){
                int notpick = 0 + dp[i-1][target];
                int pick = 1e9;
                if(coins[i] <= target)pick = 1 + dp[i][target-coins[i]];

                dp[i][target] = min(pick,notpick);
            }
        }

        if(dp[n-1][amount] >= 1e9)return -1;
        return dp[n-1][amount];
    }
};

// space optimized
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> prev(amount+1,0);

        for(int i=0;i<=amount;i++){
            if (i % coins[0] == 0)
            prev[i] = i / coins[0];
        else
            prev[i] = 1e9;
        }
        
        for(int i=1;i<n;i++){
            vector<int> cur(amount+1,0);
            for(int target = 0; target <= amount;target++){
                int notpick = 0 + prev[target];
                int pick = 1e9;
                if(coins[i] <= target)pick = 1 + cur[target-coins[i]];

                cur[target] = min(pick,notpick);
            }
            prev = cur;
        }

        if(prev[amount] >= 1e9)return -1;
        return prev[amount];
    }
};