#include <bits/stdc++.h>
using namespace std;

// memoization
class Solutionm {
    public:
        int f(int i, int n, int k, vector<int> &arr, vector<vector<int>> &dp)
        {
            if (i == 0)
            {
    
                if (k % arr[i] == 0)
                    return 1;
                else
                    return 0;
            }
            if (dp[i][k] != -1)
                return dp[i][k];
    
            int notPick = f(i - 1, n, k, arr, dp);
            int pick = 0;
            if (k >= arr[i])
                pick = f(i, n, k - arr[i], arr, dp);
    
            return dp[i][k] = pick + notPick;
        }
    public:
        int change(int amount, vector<int>& coins) {
            int n = coins.size();
            vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
            int ans = f(n - 1, n, amount, coins, dp);
            return ans;
        }
    };

// tabulation
class Solutiont {
    public:
        int change(int amount, vector<int>& coins) {
            int n = coins.size();
            const long long MOD = 2147483648LL; // 2^31
            vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));
    
            for(int i = 0; i < n; i++) dp[i][0] = 1;
            
            for(int i = 0; i <= amount; i++) {
                if(i % coins[0] == 0) dp[0][i] = 1;
            }
            
            for(int i = 1; i < n; i++) {
                for(int j = 1; j <= amount; j++) {
                    long long notpick = dp[i-1][j];
                    long long pick = 0;
                    if(j >= coins[i]) pick = dp[i][j - coins[i]];
                    dp[i][j] = (pick + notpick) % MOD;
                }
            }
            
            return (int)dp[n-1][amount];
        }
    };

    // space optimization
    class Solution {
        public:
            int change(int amount, vector<int>& coins) {
                int n = coins.size();
                const long long MOD = 2147483648LL; // 2^31
                vector<long long> prev(amount + 1, 0);
        
                for(int i = 0; i < n; i++) prev[0] = 1;
                
                for(int i = 0; i <= amount; i++) {
                    if(i % coins[0] == 0) prev[i] = 1;
                }
                
                for(int i = 1; i < n; i++) {
                vector<long long> cur(amount + 1, 0);
                cur[0]=1;
                    for(int j = 1; j <= amount; j++) {
                        long long notpick = prev[j];
                        long long pick = 0;
                        if(j >= coins[i]) pick = cur[j - coins[i]];
                        cur[j] = (pick + notpick) % MOD;
                    }
                    prev = cur;
                }
                
                return (int)prev[amount];
            }
        };

// best solution, time and space wise
class Solution {
    public:
        int change(int amount, vector<int>& coins) {
            vector<unsigned long long> dp(amount + 1, 0);
            dp[0] = 1;
    
            for (int coin : coins) {
                for (int j = coin; j <= amount; ++j) {
                    dp[j] += dp[j - coin];
                }
            }
    
            return dp[amount];
        }
    };

int main(){
    vector<int> coins = {1,2,5};
    cout << Solution().change(5,coins) << endl;
    return 0;
}