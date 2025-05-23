class Solution {
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> ds;
            // Sort the input array to group duplicates together
            sort(nums.begin(), nums.end());
            findSubsets(nums, 0, ds, ans);
            return ans;
        }
    
        void findSubsets(vector<int>& arr, int index, vector<int>& ds, vector<vector<int>>& ans) {
            // Add the current subset to the result
            ans.push_back(ds);
    
            // Explore all possible elements from the current index
            for (int i = index; i < arr.size(); i++) {
                // Skip duplicates at the same recursion level
                if (i > index && arr[i] == arr[i - 1]) continue;
    
                // Include the current element
                ds.push_back(arr[i]);
                findSubsets(arr, i + 1, ds, ans);
                // Backtrack by removing the current element
                ds.pop_back();
            }
        }
    };