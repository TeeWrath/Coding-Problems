#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> height = {10, 20, 30, 10};
    int n = height.size();
    int k=3;

    // tabulation
    vector<int> dp(n,-1); // No need to initialize with -1 for tabulation

    dp[0] = 0; // Base case: cost to reach the first stone is 0

    for(int i=1; i<n; i++){
        int mmsteps = INT_MAX;

        for(int j=1;j<=k;j++){
            if(i-j >=0){
                int jump = dp[i-j] + abs(height[i] - height[i-j]);
                mmsteps = min(jump,mmsteps);
            }
        }
        dp[i] = mmsteps;
    }
    cout << dp[n-1];
    return 0;
}