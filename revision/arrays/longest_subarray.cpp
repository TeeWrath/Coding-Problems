#include <bits/stdc++.h>
using namespace std;

int bruteLongestSubarrayWithSumK(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxCnt = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int cnt = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            cnt++;
            if (sum == k)
            {
                maxCnt = max(maxCnt, cnt);
            }
        }
    }

    return maxCnt;
}

// optimal approach
int longestSubarrayWithSumK(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxCnt = 0;
    int i = 0, j = 0;
    long long sum = 0;

    while (i < n && j < n)
    {
        sum += nums[j];
        while (i<=j && sum > k)
        {
            sum -= nums[i];
            i++;
        }

        if (sum == k)
        {
            maxCnt = max(maxCnt, j + 1 - i);
        }

        j++;
    }

    return maxCnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << endl;
    cout << "Now the k: ";
    int k;
    cin >> k;

    int res = longestSubarrayWithSumK(nums, k);
    cout << "Result is: " << res << endl;

    // for(int i=0;i<n;i++){
    //     cout << nums[i] << " ";
    // }
    return 0;
}