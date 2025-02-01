#include<bits/stdc++.h>
using namespace std;

// Iteratively
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};

// Recursively
class Recursive {
    public:
    int binarySearch(vector<int> & nums, int target, int low, int high){
        if(low > high) return -1;
        int mid = (low + high)/2;
        if(nums[mid] == target) return mid;
        else if(target > nums[mid]) return binarySearch(nums,target, mid + 1, high);
        return binarySearch(nums, target, low, mid -1);
    }
};

int main(){
    Recursive rec = Recursive();
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int res = rec.binarySearch(arr,9,0,9);
    cout << res ;
    return 0;
}
