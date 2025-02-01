#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    int num = n;
    int l = 0, h = n - 1;

    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (nums[mid] >= target)
        {
            num = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }

    return num;
}

int main()
{
    vector<int> arr = {1, 3,5,6};
    int res = searchInsert(arr,5);
    cout << res;
    return 0;
}