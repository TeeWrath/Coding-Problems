#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0,r=n-1;

        while(l<r){
            int m = l+(r-l)/2;
            if(nums[m] > nums[r])l=m+1;
            else r=m;
        }

        int piv = l;
        int res = binarySearch(nums,target,0,piv-1);
        return res != -1? res : binarySearch(nums,target,piv,n-1);
    }

private:
    int binarySearch(vector<int>& nums,int target, int l, int r){
        while(l<=r){
            int m = l + (r-l)/2;
            if(target == nums[m])return m;
            else if(target > nums[m])l=m+1;
            else r=m-1;
        }

        return -1;
    }
};

int main(){
    vector<int> nums = {3,5,6,0,1,2};
    int target;cin >> target;
    cout << Solution().search(nums,target) << endl;
    return 0;
}