#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int f(int i, int count,int n,int total, int sum, vector<int> &nums)
    {
        if(count == n) return abs(2*sum - total);
        if(i == nums.size())return INT_MAX;

        int pick = f(i+1,count + 1,n,total, sum + nums[i],nums);
        int notPick = f(i+1,count,n,total,sum,nums);

        return min(pick, notPick);
    }

public:
    int minimumDifference(vector<int> &nums)
    {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        return f(0,0, n / 2,total,0, nums);
    }
};

int main()
{
    vector<int> nums = {2, -1, 0, 4, -2, -9};
    cout << Solution().minimumDifference(nums) << endl;
    return 0;
}