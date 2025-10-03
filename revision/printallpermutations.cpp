#include <bits/stdc++.h>
using namespace std;

class Solution
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

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
