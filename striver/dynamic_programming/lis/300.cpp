#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int f(int i,int j, int n, vector<int>& nums,vector<vector<int>> &dp){
            if(i==n)return 0;
            if(dp[i][j+1] != -1)return dp[i][j+1];
            int pick=0;
            int notpick = f(i+1,j,n,nums,dp);
            if(j==-1 || nums[i]>nums[i-1])pick = 1+ f(i+1,i,n,nums,dp);

            return dp[i][j+1] = max(pick,notpick);
        }
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> dp(n,vector<int>(n+1,-1));
            return f(0,-1,n,nums,dp);
        }
    };

int main(){
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << Solution().lengthOfLIS(nums)<< endl;
    return 0;
}