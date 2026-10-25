#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int ROWS = matrix.size();    // rows
        int COLS = matrix[0].size(); // cols

        int top=0,bot = ROWS-1;
        while(top <= bot){
            int row = (top +bot)/2;
            if(target > matrix[row][COLS-1])top=row+1;
            else if(target < matrix[row][0])bot = row-1;
            else break;
        }

        if(!(top<=bot))return false;

        int row = (top+bot)/2;
        int l=0,r=COLS-1;
        while(l<=r){
            int m = (l+r)/2;
            if(target > matrix[row][m])l=m+1;
            else if(target < matrix[row][m])r=m-1;
            else return true;
        }

        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 2, 4, 8}, {10, 11, 12, 13}, {14, 20, 30, 40}};
    int target;
    cin >> target;
    cout << Solution().searchMatrix(matrix, target) << endl;
    return 0;
}