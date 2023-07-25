/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

*/

/*BRUTE FORCE - MY APPROACH*/
class Solution {
    public int searchInsert(int[] nums, int target) {
        int i=0;
        while(i<nums.length){
            if(nums[i] == target)
                return i;
            else if(target < nums[i])
                return i;
            i++;
        }
        return i;
    }
}

/*USING BINARY SEARCH*/
class Sol {
    public int searchInsert(int[] nums, int target) {
        int start =0;
        int end = nums.length -1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(nums[mid] == target)return mid;
            else if(nums[mid] < target) start = mid+1;
            else end = mid-1;
        }
        return start;
    }
}
