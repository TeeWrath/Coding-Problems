#include<bits/stdc++.h>
using namespace std;

// Linear search
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        for(int i=0; i<n; i++){
            if(i == 0){
                if(nums[i] != nums[i+1]) return nums[i];
            }
            else if(i == n-1){
                if(nums[i] != nums[i-1]) return nums[i];
            }
            else{if(nums[i-1] != nums[i] && nums[i] != nums[i+1]) return nums[i];}
        }

        return -1;
    }
};

// Using XOR
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;

        for(int i=0; i<n; i++){
            xorr = xorr^nums[i];
        }

        return xorr;
    }
};

// Binary search
