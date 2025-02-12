#include<bits/stdc++.h>
using namespace std;

// Binary search on each row - O(n + logm)
class Solution {
public:

    bool binS(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0; int high = n-1;

        while(low <= high){
            int mid = (low+high)/2;

            if(nums[mid] == target) return true;
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); // Rows
        int m = matrix[0].size(); // Columns

        for(int i=0; i<n; i++){
            if(target >= matrix[i][0] && target <= matrix[i][m-1]){
                return binS(matrix[i], target);
            }
        }
        return false;
    }
};

// Binary search imagining the matrix to be a one-d array - O(log(m*n))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); // Rows
        int m = matrix[0].size(); // Columns

       int low = 0; int high = n*m -1;
       while(low <= high){
        int mid = (low+high)/2;
        int row = mid/m; int col = mid%m; // Doing this to find hypothetical index in imagined 1D array
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] > target) high = mid-1;
        else low = mid+1;
       }
        return false;
    }
};