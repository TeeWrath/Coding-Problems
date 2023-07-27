class Solution {
    public int[] productExceptSelf(int[] nums) {
        int pre =1;
        int arr[] = new int[nums.length];
        arr[0] = pre;
        pre = pre*nums[0];
        for(int i=1; i<nums.length; i++){
            arr[i] = pre;
            pre = pre*nums[i];
        }
        int pos =1;
        arr[nums.length-1] = pos*arr[nums.length-1];
        pos = pos*nums[nums.length-1];
        for(int i=nums.length-2; i>=0; i--){
            arr[i] = pos*arr[i];
            pos = pos*nums[i];
        }
        return arr;
    }
}