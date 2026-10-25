#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        int res = nums[0];
        int n = nums.size();
        int l=0,r=n-1;

        while(l<=r){
            if(nums[l] < nums[r]){
                res = min(res,nums[l]);
                break;
            }
            int m = l + (r-l)/2;
            res = min(res,nums[m]);
            if(nums[m] >= nums[l]){
                l = m+1;
            }else r=m-1;
        }

        return res;
    }
};

int main(){
    vector<int> nums = {4,5,6,7};
    cout << Solution().findMin(nums) << endl;
    return 0;
}