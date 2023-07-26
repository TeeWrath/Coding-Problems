import java.lang.*;
import java.util.*;

class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i=0; i<nums.length; i++){

            if(!mp.containsKey(nums[i])){
                mp.put(nums[i], 1);
            }
            int freq = mp.get(nums[i]);
            freq++;
            mp.put(nums[i], freq);
        }

        int arr[] = new int[k];
        int j=0;
        for(int i=0; i<k ; i++){
            int freq = 0;
            int max = 0;
            for(Map.Entry<Integer, Integer> val : mp.entrySet()){
                if(val.getValue() > freq){
                    freq = val.getValue();
                    max = val.getKey();
                }
            }
            mp.put(max, 0);
            arr[j] = max;
            j++;
        }
        return arr;
    }
}