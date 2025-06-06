#include <bits/stdc++.h>
using namespace std;

// Brute solution
int func(vector<int> &nums, int k)
{
    int n = nums.size();
    int res = 0;
    int s = k;
    for (int i = 0; i < n; i++)
    {
        k = s;
        for (int j = i; j < n; j++)
        {
            if (nums[j] % 2 != 0)
                k--;
            if (k == 0)
                res++;
        }
    }

    return res;
}

// optimal solution - same as binary subarray sum
int atMost(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;
    int l = 0, r = 0, count = 0, sum = 0;
    while (r < nums.size())
    {
        sum += nums[r] % 2;
        while (sum > goal)
        {
            sum -= nums[l] % 2;
            l++;
        }
        count += r - l + 1;
        r++;
    }
    return count;
}
int numberOfSubarrays(vector<int> &nums, int k)
{
    return atMost(nums, k) - atMost(nums, k - 1);
}

int main()
{
    vector<int> nums = {2, 4, 6};
    int k = 1;
    cout << func(nums, k) << endl;
    return 0;
}