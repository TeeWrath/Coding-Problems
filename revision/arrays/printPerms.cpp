#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    void generatePerms(vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans, vector<int> &freq)
    {
        if (ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!freq[i])
            {
                ds.push_back(nums[i]);
                freq[i] = 1;
                generatePerms(nums, ds, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<int>> printAllPerms(vector<int> nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(n, 0);
        generatePerms(nums, ds, ans, freq);
        return ans;
    }
};

class Solution2
{
public:
    void generatePerms(int index,vector<int> &nums,  vector<vector<int>> &ans)
    {
        if (index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
           
                swap(nums[index],nums[i]);
                generatePerms(index+1,nums,  ans );
                swap(nums[index],nums[i]);
                
            
        }
    }

public:
    vector<vector<int>> printAllPerms(vector<int> nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        generatePerms(0,nums,ans);
        return ans;
    }
};

int main()
{
    vector<vector<int>> ans = Solution2().printAllPerms({1, 2, 3});
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}