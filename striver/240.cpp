#include<bits/stdc++.h>
using namespace std;

// First approach
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
        int n = matrix.size(); //rows
        int m = matrix[0].size(); //columns
        bool res = false;
        for(int i=0; i<n; i++){
            res = binS(matrix[i], target);
            if(res) return res;
        }
        return res;
    }
};

// Optimal Approach
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(); //rows
        int m = matrix[0].size(); //columns
        int row=0; int col = m-1;

        while(row < n && col >= 0){
            if(matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) row++;
            else col--;
        }

        return false;
    }
};