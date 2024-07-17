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

// Optimal Method
class Solution1 {
  List<int> twoSum(List<int> nums, int target) {
    Map<int, int> numMap = {};
    for (int i = 0; i < nums.length; i++) {
      int compliment = target - nums[i];
      if (numMap.containsKey(compliment)) {
        return [numMap[compliment]!, i];
      }
      numMap[nums[i]] = i;
    }
    throw Exception("No Solution Found");
  }
}

void main() {
  // List<int> nums = [2, 5, 5, 11];
  // int target = 10;
  List<int> nums = [14,15,89,100,56,21];
  int target = 110;
  List<int> res = Solution().twoSum(nums, target);
  print(res);
}
