#include<bits/stdc++.h>
using namespace std;

// Brute force
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j= i; j<n; j++){
                int sum = 0;
                for(int k=i; k<=j; k++){
                    sum += nums[k];
                }
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

// Better approach
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j= i; j<n; j++){
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

// Optimal Approach - Kadane's Algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];

            maxSum = max(sum, maxSum);

            if(sum < 0) sum = 0;
        }

        return maxSum;
    }
};

// New correct approach, dealing with negative numbers too
class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            int sum = nums[0];
            int cnt=nums[0];
    
            for(int i=1;i<n;i++){
                cnt = max(nums[i], cnt + nums[i]);
                sum = max(cnt,sum);
            }
    
            return sum;
        }
    };