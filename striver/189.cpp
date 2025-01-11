
// Using duplicate array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // duplicate vector
        vector<int> dup = nums;

        for(int i=0; i<nums.size(); i++){
            nums[(i+k) % n] = dup[i];
        }
    }
};

// On the same input array - using reverse approach
class Solution {
public:
    void reverseArray(vector<int>& nums, int start, int end){
        while(start <= end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        // to ensure k is within the bounds
        k = k%n;

        reverseArray(nums,0,n-k-1);
        reverseArray(nums,n-k,n-1);
        reverseArray(nums,0,n-1);
    }
};