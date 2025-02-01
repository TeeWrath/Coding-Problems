#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &nums)
{
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Function to find the first occurrence (lower bound)
int findFirstOccurrence(vector<int> &arr, int k)
{
    int n = arr.size();
    int ans = -1;
    int l = 0, h = n - 1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] >= k)
        {
            if (arr[mid] == k) ans = mid;
            h = mid - 1; // Move left to find first occurrence
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

// Function to find the last occurrence (upper bound - 1)
int findLastOccurrence(vector<int> &arr, int k)
{
    int n = arr.size();
    int ans = -1;
    int l = 0, h = n - 1;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] <= k)
        {
            if (arr[mid] == k) ans = mid;
            l = mid + 1; // Move right to find last occurrence
        }
        else
        {
            h = mid - 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans(2, -1);
    ans[0] = findFirstOccurrence(nums, target);
    ans[1] = findLastOccurrence(nums, target);
    return ans;
}

int main()
{
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    vector<int> res = searchRange(arr, 6);
    printArray(res); // Should print [-1, -1] since 6 is not in the array

    return 0;
}
