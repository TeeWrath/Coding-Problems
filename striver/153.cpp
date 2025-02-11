#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int low=0; int high = n-1;

        while(low <= high){
            int mid = (low+high)/2;
            // min = min(min,nums[mid]);

            if(nums[low] <= nums[mid]){
                ans = min(ans,nums[low]);
                low = mid + 1;
            }
            else{
                ans= min(ans,nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};