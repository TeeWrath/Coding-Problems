#include<bits/stdc++.h>
using namespace std;

int frogJump(int index, vector<int> &height, vector<int>&dp){
    if(index ==0)return 0;
    if(dp[index] != -1)return dp[index];
    int jump2 = INT_MAX;
    int jump1 = frogJump(index - 1,height,dp) + abs(height[index] - height[index-1]);
    if(index > 1) jump2 = frogJump(index-2,height,dp) + abs(height[index] - height[index-2]);
    return dp[index] = min(jump1,jump2);
}


int main(){
    vector<int> height = {10,20,30,10};
    int n = height.size();
    vector<int> dp(n,-1);
    cout << frogJump(n-1,height,dp);
    return 0;
}