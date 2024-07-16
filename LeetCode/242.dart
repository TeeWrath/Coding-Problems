// Method - 1
class Solution {
  bool isAnagram(String s, String t) {
    // making both lowercase (if any letter is capital)
    s.toLowerCase();
    t.toLowerCase();
    // splitting both strings into lists of strings
    var sSort = s.split('');
    sSort.sort();
    var tSort = t.split('');
    tSort.sort();
    // joining the lists to create individual strings then checking if they are equal
    return sSort.join('') == tSort.join('');
  }
}

// Method -2 (Fastest)
class Solution2 {
  bool isAnagram(String s, String t) {
    s.toLowerCase();
    t.toLowerCase();
    // if length unequal, they surely are no anagrams
    if (s.length != t.length) return false;
    // initialising an integer list with 26 zeroes
    final List<int> list = List.filled(26, 0);
    for (int i = 0; i < s.length; i++) {
      // increase value for each letter in the list indexes, by comparing to ASCII code values
      list[s.codeUnitAt(i) - 97]++;
      // decrementing values in same way as above (so that finally we should have 26 zeroes again, if it is anagram)
      list[t.codeUnitAt(i) - 97]--;
    }
    // check if each value in list is zero
    return list.every((c) => c == 0);
  }
}

void main() {
  String s = "care";
  String t = "race";

  bool res = Solution2().isAnagram(s, t);
  print(res);
}
