#include <bits/stdc++.h>
using namespace std;

class Solutionm
{
public:
    int f(int i, int j, int n, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i == n)
            return 0;
        if (dp[i][j + 1] != -1)
            return dp[i][j + 1];
        int pick = 0;
        int notpick = f(i + 1, j, n, nums, dp);
        if (j == -1 || nums[i] > nums[i - 1])
            pick = 1 + f(i + 1, i, n, nums, dp);

        return dp[i][j + 1] = max(pick, notpick);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, n, nums, dp);
    }
};

class Solutiont
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= -1; j--)
            {
                int pick = 0;
                int notpick = dp[i + 1][j+1];
                if (j == -1 || nums[i] > nums[j])
                    pick = 1 + dp[i + 1][i+1];

                dp[i][j + 1] = max(pick, notpick);
            }
        }

        return dp[0][0];
    }
};

class Solutions
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> after(n + 1, 0),cur(n+1,0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= -1; j--)
            {
                int pick = 0;
                int notpick = after[j+1];
                if (j == -1 || nums[i] > nums[j])
                    pick = 1 + after[i+1];

                cur[j + 1] = max(pick, notpick);
            }
            after = cur;
        }

        return cur[0];
    }
};

// lower bound
class Solutionl
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n,1);
        int maxi=1;

        for(int i=0;i<n;i++){
            for(int prev=0;prev<=i;prev++)if(nums[prev] < nums[i])dp[i] = max(dp[i],1+dp[prev]);
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};

// printing
class Solution
{
public:
    void lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n,1),hash(n);
        int maxi=1;
        int lastIndex=0;

        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int prev=0;prev<=i;prev++){
                if(nums[prev] < nums[i] && 1+dp[prev] > dp[i]){
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }

        reverse(temp.begin(),temp.end());

        for(auto it:temp){
            cout << it << " ";
        }
    }
};

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution().lengthOfLIS(nums);
    return 0;
}