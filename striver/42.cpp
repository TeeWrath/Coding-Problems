#include <bits/stdc++.h>
using namespace std;

// Optimized for time but not space
vector<int> findRightMax(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans = arr;
    int i = n - 2;
    while (i >= 0)
    {
        ans[i] = max(arr[i + 1], ans[i + 1]);
        i--;
    }

    return ans;
}

int trap(vector<int> &height)
{
    int n = height.size();
    int waterUnits = 0;
    int leftMax = height[0];
    vector<int> rightMax = findRightMax(height);
    for (int i = 1; i < n; i++)
    {
        leftMax = max(leftMax, height[i - 1]);
        if ((height[i] < leftMax) && (height[i] < rightMax[i]))
        {
            waterUnits += min(leftMax, rightMax[i]) - height[i];
        }
    }

    return waterUnits;
}

// Two pointer approach - most optimal
int trap(vector<int> &height)
{
    int n = height.size();
    int left = 0;
    int right = n - 1;
    int maxLeft = 0;
    int maxRight = 0;
    int res = 0;
    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] > maxLeft)
            {
                maxLeft = height[left];
            }
            else
            {
                res += maxLeft - height[left];
            }
            left++;
        }
        else
        {
            if (height[right] > maxRight)
            {
                maxRight = height[right];
            }
            else
            {
                res += maxRight - height[right];
            }
            right--;
        }
    }

    return res;
}

int main()
{
    // vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height = {4, 2, 0, 3, 2, 5};
    cout << "Water units that can be trapped: " << trap(height) << endl;
    return 0;
}