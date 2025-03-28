#include<bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> &matrix)
{
int n = matrix.size();
int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void printArray(vector<int> & arr){
    int n = arr.size();

    for(int i=0; i<n ;i++){
        cout << arr[i] << " ";
    }
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(); // rows
        int m = matrix[0].size(); // Columns

        int top = 0; 
        int left = 0;
        int right = m - 1;
        int bottom = n - 1;

        vector<int> ans;

        while(top <= bottom && left <= right){
            for(int i = left; i<= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i= top; i<= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right --;

            if(top <= bottom){
                for(int i= right; i>= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom --;
            }
            if(left <= right){
                for(int i= bottom; i>= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol = Solution();
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    cout << "Before Spiral" << endl;
    printMatrix(matrix);
    vector<int> soluvec = sol.spiralOrder(matrix);
    cout << "After Spiral" << endl;
    printArray(soluvec);
    return 0;
}