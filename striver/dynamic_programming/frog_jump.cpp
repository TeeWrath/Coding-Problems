#include<bits/stdc++.h>
using namespace std;

// memoization
int frogJump(int index, vector<int> &height, vector<int>&dp){
    if(index ==0)return 0;
    if(dp[index] != -1)return dp[index];
    int jump2 = INT_MAX;
    int jump1 = frogJump(index - 1,height,dp) + abs(height[index] - height[index-1]);
    if(index > 1) jump2 = frogJump(index-2,height,dp) + abs(height[index] - height[index-2]);
    return dp[index] = min(jump1,jump2);
}


int main() {
    vector<int> height = {10, 20, 30, 10};
    int n = height.size();

    // tabulation
    vector<int> dp(n); // No need to initialize with -1 for tabulation

    dp[0] = 0; // Base case: cost to reach the first stone is 0

    for (int i = 1; i < n; i++) {
        int jump2 = INT_MAX;
        int jump1 = dp[i - 1] + abs(height[i] - height[i - 1]);
        if (i > 1) {
            jump2 = dp[i - 2] + abs(height[i] - height[i - 2]);
        }
        dp[i] = min(jump1, jump2);
    }

    cout << dp[n - 1] << ": Answer";

    // space optimization
    int prev =0;
    int prev2 = 0;
    for(int i=1; i<n;i++){
        int jump2 = INT_MAX;
        int jump1 = prev + abs(height[i] - height[i-1]);
        if(i>1) jump2 = prev2 + abs(height[i]-height[i-2]);

        int cur = min(jump1,jump2);
        prev2=prev;
        prev=cur;
    }

    cout << prev << " is answer";
    return 0;
}