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

// using stack - greatest elements to the right
vector<int> ngstackToRight(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    stack<int> st; // stack to store indices
    
    // Iterate from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        // Pop elements from stack while they are smaller than current element
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            st.pop();
        }
        
        // If stack is not empty, count elements greater than current
        if (!st.empty())
        {
            ans[i] = st.size();
        }
        
        // Push current index to stack
        st.push(i);
    }
    
    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 4, 2};
    vector<int> ans = ngstackToRight(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}