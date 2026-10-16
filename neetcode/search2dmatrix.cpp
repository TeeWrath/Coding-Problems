#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();    // rows
        int n = matrix[0].size(); // cols

        int row = 0, col = 0;
        while (row < m && col < n)
        {
            if (row > 0 && matrix[row][0] > target)
                row--;
            else if (row < m && matrix[row][n - 1] < target)
                row++;
            else
            {
                int l = 0, r = n - 1;
                while (l <= r)
                {
                    int m = l + ((r - l) / 2);
                    if (matrix[row][m] == target)
                        return true;
                    else if (matrix[row][m] > target)
                    {
                        r = m - 1;
                    }
                    else
                    {
                        l = m + 1;
                    }
                }
            }
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