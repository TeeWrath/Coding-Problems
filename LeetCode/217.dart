class Solution {
  bool containsDuplicate(List<int> nums) {
    Set<int> s = {};
    for (int n in nums) {
      if (s.contains(n)) return true;
      s.add(n);
    }
    return false;
  }
}

void main() {
  List<int> num = [1,1,1,3,3,4,3,2,4,2];
  bool res = Solution().containsDuplicate(num);
  print(res);
}
