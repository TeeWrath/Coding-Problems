#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> &matrix, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Brute force
class Solution
{
public:
    vector<vector<int>> rotateImg(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        vector<vector<int>> ans(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // position can be found by pattern mapping
                ans[j][n - 1 - i] = matrix[i][j];
            }
        }

        return ans;
    }
};

class Solution1
{
public:
    void rotateImg(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            // j = i+1 so that only unique swaps occur otherwise repeated swaps will lead to no transpose
            for (int j = i+1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reversing each row;
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main()
{
    Solution1 sol = Solution1();
    vector<vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    int n = matrix.size();
    cout << "Before Rotation" << endl;
    printMatrix(matrix, n);
    sol.rotateImg(matrix);
    cout << "After Rotation" << endl;
    printMatrix(matrix, n);
    return 0;
}