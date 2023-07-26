import java.util.*;
import java.lang.*;
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> mp = new HashMap();

        for(String word : strs){
            char[] cr = word.toCharArray();
            Arrays.sort(cr);
            String sc = new String(cr);
            if(!mp.containsKey(sc)){
                mp.put(sc, new ArrayList<String>());
            }
            mp.get(sc).add(word);; 
        }
        return new ArrayList<>(mp.values());
    }
}
