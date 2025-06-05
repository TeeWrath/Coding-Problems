#include<bits/stdc++.h>
using namespace std;

// TC - O(2n), SC - O(1) - MOST OPTIMAL
int longestOnes1(vector<int>& nums, int k) {
    int n = nums.size();
    int l=0,r=0;
    int lenMax=0;
    int zeroes =0;

    while(r < n){
        if(nums[r] == 0) zeroes++;
        while(zeroes > k){
            if(nums[l] == 0)zeroes--;
            l++;
        }
        if(zeroes <= k){
            int len  = r - l + 1;
            lenMax = max(len,lenMax);
        }
        r++;
    }

    return lenMax;
}

// TC - O(2n) but this one is less better
int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int l=0,r=0;
    int lenMax=0;
    int zeroes =0;

    while(r < n){
        if(nums[r] == 0) zeroes++;
        if(zeroes > k){
            if(nums[l] == 0)zeroes--;
            l++;
        }
        if(zeroes <= k){
            int len  = r - l + 1;
            lenMax = max(len,lenMax);
        }
        r++;
    }

    return lenMax;
}

int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << longestOnes(nums,k) << endl;
    return 0;
}