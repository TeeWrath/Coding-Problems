/*You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).Find two lines that together with the x-axis form a container, such that the container contains the most water.Return the maximum amount of water a container can store.Notice that you may not slant the container.*/
class Solution {

    public static int max(int n, int m){
        int res = (n > m) ? n : m;
        return res;
    }

    public static int min(int n, int m){
        int res = (n < m) ? n : m;
        return res;
    }
    public int maxArea(int[] height) {
        int left = 0;
        int right = height.length -1;
        int maxArea = 0, curArea = 0;

        while( left < right ){
            curArea = (min( height[left], height[right] )) * (right - left);
            maxArea = max(maxArea, curArea);
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;        
    }        
}
