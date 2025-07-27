#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &nums)
    {
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick += prev2;
            int nonPick = prev;

            int cur = max(pick, nonPick);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }

public:
    int rob(vector<int> &nums)
    {
        vector<int> arr1,arr2;
        if(nums.size()==1)return nums[0];

        for(int i=0; i<nums.size();i++){
            if(i!=0)arr1.push_back(nums[i]);
            if(i!=nums.size()-1)arr2.push_back(nums[i]);
        }

        long long int ans1 = solve(arr1);
        long long int ans2 = solve(arr2);

        return max(ans1,ans2);
    }
};