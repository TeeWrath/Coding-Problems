#include<bits/stdc++.h>
using namespace std;

// My approach
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        stable_sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(nums[i] != i) return i;
        }
        return n;
    }
};

// Using Summation
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s1 = (n*(n+1))/2;

        int s2=0;
        for(int i=0; i<n; i++){
            s2 += nums[i];
        }

        return s1-s2;
    }
};