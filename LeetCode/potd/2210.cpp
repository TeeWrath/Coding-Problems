#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countHillValley(vector<int>& nums) {
            int cnt=0;
            int l=nums[0];
    
            for(int i=1;i<nums.size()-1;++i){
                if(nums[i] != nums[i+1]){
                    if((nums[i] < l && nums[i] < nums[i+1]) || (nums[i] > l && nums[i] > nums[i+1]))++cnt;
                    l = nums[i];
                }
            }
    
            return cnt;
        }
    };