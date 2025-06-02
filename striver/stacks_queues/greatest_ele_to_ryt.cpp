#include <bits/stdc++.h>
using namespace std;

// using arrays only - greatest elements to the right
vector<int> ngeToRight(vector<int> &nums)
{
    vector<int> ans(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] > nums[i])
                ans[i]++;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 4, 2};
    vector<int> ans = ngeToRight(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}