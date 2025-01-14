#include<bits/stdc++.h>
using namespace std;

// Using map
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        map<int,int> mpp;

        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }

        for(auto it : mpp){
            if(it.second > n/2) return it.first;
        }

        return -1;
    }
};

// Optimal approach
// (If it is given that there might be a majority element)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        int ele=0;

        for(int i=0; i<n; i++){
            if(cnt == 0){
                ele = nums[i];
            }
            else if(nums[i] == ele){
                cnt++;
            }
            else {
                cnt--;
            }

            // these lines check if it is majority element
            int cnt1 =0;
            for(int i=0; i<n; i++){
                if(nums[i] == ele) cnt1++;
            }

            if(cnt1 > n/2) return ele;
        }

        return -1;
    }
};

// if it is given that there surely exists a majority element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        int ele;

        for(int i=0; i<n; i++){
            if(cnt == 0){
                cnt=1;
                ele = nums[i];
            }
            else if(nums[i] == ele){
                cnt++;
            }
            else {
                cnt--;
            }
        }

        return ele;
    }
};