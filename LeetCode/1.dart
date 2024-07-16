// Brute force approach
class Solution {
  List<int> twoSum(List<int> nums, int target) {
    for (int i = 0; i < nums.length; i++) {
      for (int j = i+1; j < nums.length; j++) {
        if (nums[i] + nums[j] == target) {
          return [i, j];
        }
      }
    }
    return [];
  }
}

void main() {
  // List<int> nums = [2, 5, 5, 11];
  // int target = 10;
  List<int> nums = [3,2,3];
  int target = 6;
  List<int> res = Solution().twoSum(nums, target);
  print(res);
}
