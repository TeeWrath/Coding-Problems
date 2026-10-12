#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(nums[0] > 0)break;
            if(i>0 && nums[i] == nums[i-1])continue;

            int l = i+1,r=n-1;
            while(l<r){
                if(nums[l]+nums[r] > -nums[i]) r--;
                else if(nums[l]+nums[r] < -nums[i])l++;
                else {ans.push_back({nums[i],nums[l],nums[r]});
                l++;
                r--;}
            }
        }

        return ans;
    }
};

int main(){
    vector<int> nums = {1,-1,-1,0};

    vector<vector<int>> res = Solution().threeSum(nums);

    for(auto i: res){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}