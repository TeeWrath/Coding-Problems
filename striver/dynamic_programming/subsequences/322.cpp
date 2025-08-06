#include <bits/stdc++.h>
using namespace std;

class Solution
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
            pick = f(i, n, k - arr[i], arr, dp);

        return dp[i][k] = min(pick,notPick);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        for(int i=0; i<=amount;i++){
            bool dum = f(n-1,n,amount,coins,dp);
        }

        int cnt=0;
        for(int i=0;i<=amount;i++){
            if(dp[n-1][i]==true){

            }
        }
    }
};