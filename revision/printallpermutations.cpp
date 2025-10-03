#include <bits/stdc++.h>
using namespace std;

class Solutionm
{
public:
    void f(vector<int> &ds,vector<vector<int>> & ans, vector<int> &mpp, vector<int> &nums){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!mpp[i]){
                ds.push_back(nums[i]);
                mpp[i] = 1;
                f(ds,ans,mpp,nums);
                mpp[i] = 0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> ds;
        vector<vector<int>> ans;
        vector<int> mpp(nums.size(),0);
        f(ds,ans,mpp,nums);
        return ans;

    }
};

class Solution
{
    public:
        void f(int ind, vector<int> &nums, vector<vector<int>> &ans){
            if(ind == nums.size()){
                ans.push_back(nums);
                return;
            }

            for(int i=ind;i<nums.size();i++){
                swap(nums[ind],nums[i]);
                f(ind+1,nums,ans);
                swap(nums[ind],nums[i]);
            }
        }
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        f(0,nums,ans);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int ele; cin >> ele;
        arr.push_back(ele);
    }
    vector<vector<int>> ans = Solution().permute(arr);
    for(int i=0;i<ans.size();i++){
        for(auto it: ans[i]){
            cout << it << ' ';
        }
        cout << '\n';
    }
    return 0;
}
