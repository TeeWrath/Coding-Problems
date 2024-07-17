class Solution {
  List<List<String>> groupAnagrams(List<String> strs) {
    Map<String, List<String>> hMap = {};
    for (String s in strs) {
      List<int> count = List.filled(26, 0);
      for (int c = 0; c < s.runes.length; c++) {
        count[s.codeUnitAt(c) - 97] += 1;
      }
      // Use a list to store the count as the key
      var key = count.join(',');
      if (!hMap.containsKey(key)) {
        hMap[key] = [];
      }
      hMap[key]!.add(s);
    }
    return hMap.values.toList();
  }
}

void main() {
  Solution solution = Solution();
  List<String> input = ["eat", "tea", "tan", "ate", "nat", "bat"];
  print(solution.groupAnagrams(input));
}
