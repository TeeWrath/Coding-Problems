#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        for(int i=0;i<n-1;i++){
            if(nums[i] > nums[i+1]){
                cnt++;
                if(cnt >1)return false;
            }
        }
        if(cnt == 1 && (nums[0] < nums[n-1]))return false;
        return true;
    }
};